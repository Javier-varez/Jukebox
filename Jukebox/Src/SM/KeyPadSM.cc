/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: KeyPadSM.h
 * Brief: State Machine for KeyPad
 * Module: StateMachine
 */

#include "SM/KeyPadSM.h"
#include "OS/UniqueLock.h"
#include "Logger/Logger.h"
#include "KeyPad/KeyPadFactory.h"

namespace ATE::SM
{
	constexpr static std::uint32_t KEYPAD_TIMEOUT_MS = 2000;

	KeyPadSM::KeyPadSM() :
		OSAL::Task("KeyPadSM", osPriorityHigh, 2048),
		KeyPad(Device::KeyPadFactory::GetAnalogKeypad()),
		EventQueue(10),
		state(State_Idle)
	{

	}

	KeyPadSM::State KeyPadSM::GetState()
	{
		OSAL::UniqueLock l(stateMutex);
		return state;
	}

	void KeyPadSM::SetState(KeyPadSM::State s)
	{
		OSAL::UniqueLock l(stateMutex);
		state = s;
	}

	void KeyPadSM::Subscribe(KeyPadSM::Callback_t cb)
	{
		OSAL::UniqueLock l(cbMutex);
		callback = cb;
	}

	void KeyPadSM::Notify(EventType type, char letter, char number)
	{
		OSAL::UniqueLock l(cbMutex);
		if (callback != nullptr)
		{
			callback(type, letter, number);
		}
	}

	bool KeyPadSM::KeyPadCb(char key, Device::IKeyPad::KeyState state)
	{
		EventQueue.Push(KeyEvent(key, state), 0);
		Logger::GetLogger().Log(
							Logger::LogLevel_DEBUG, "Key %c, state %d\n", key, state);
		return true;
	}

	void KeyPadSM::Init()
	{
		// Register KeyPad Callback Handler
		KeyPad.Subscribe(
				std::bind(&KeyPadSM::KeyPadCb,
						this,
						std::placeholders::_1,
						std::placeholders::_2)
		);

	}

	bool KeyPadSM::Run()
	{
		KeyEvent event;
		EventQueue.Pop(event, KEYPAD_TIMEOUT_MS);

		static int key_timeout = 0;

		switch (GetState())
		{
		case KeyPadSM::State_Idle:
			if ((event.state == Device::IKeyPad::KEY_PRESSED) && IsLetter(event.key))
			{
				letter = event.key;
				Logger::GetLogger().Log(Logger::LogLevel_DEBUG, "Selected key %c\n", event.key);
				SetState(State_SelectedLetter);
			}
			else if ((event.state == Device::IKeyPad::KEY_PRESSED) && (event.key == '0'))
			{
				SetState(State_DetectedPossibleStop);
			}
			break;
		case KeyPadSM::State_SelectedLetter:
			if ((event.state == Device::IKeyPad::KEY_RELEASED) && event.key == letter)
			{
				SetState(State_ReleasedLetter);
			}
			break;
		case KeyPadSM::State_ReleasedLetter:
			if (event.state == Device::IKeyPad::KEY_EVENT_NONE)
			{
				// Exit because of timeout
				key_timeout++;
				if (key_timeout == 5)
				{
					key_timeout = 0;
					SetState(State_Idle);
					Logger::GetLogger().Log(Logger::LogLevel_DEBUG, "%s: %s - Exit because of timeout\n", __FILE__, __func__);
				}
			}
			else if ((event.state == Device::IKeyPad::KEY_PRESSED) && IsNumber(event.key))
			{
				number = event.key;
				SetState(State_SelectedNumber);
			}
			else if ((event.state == Device::IKeyPad::KEY_PRESSED) && IsLetter(event.key))
			{
				letter = event.key;
				SetState(State_SelectedLetter);
			}
			break;
		case KeyPadSM::State_SelectedNumber:
			if ((event.state == Device::IKeyPad::KEY_RELEASED) && event.key == number)
			{
				Logger::GetLogger().Log(
						Logger::LogLevel_DEBUG,
						"%s: %s - PlaySong %c%c\n",
						__FILE__,
						__func__,
						letter,
						number);
				Notify(Event_PlaySong, letter, number);
				SetState(State_Idle);
			}
			break;
		case KeyPadSM::State_DetectedPossibleStop:
			if (event.state == Device::IKeyPad::KEY_EVENT_NONE)
			{
				Notify(Event_StopPlayback);
				SetState(State_Idle);
			}
			else if ((event.state == Device::IKeyPad::KEY_RELEASED) && (event.key == '0'))
			{
				SetState(State_Idle);
			}
			break;
		}

		return true;
	}

	bool KeyPadSM::IsLetter(char c)
	{
		return c >= 'A' && c <= 'Z';
	}

	bool KeyPadSM::IsNumber(char c)
	{
		return c >= '0' && c <= '9';
	}
}
