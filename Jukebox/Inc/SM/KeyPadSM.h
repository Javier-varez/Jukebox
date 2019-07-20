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

#ifndef INC_SM_KEYPADSM_H_
#define INC_SM_KEYPADSM_H_

#include "OS/Task.h"
#include "OS/Queue.h"
#include "OS/Mutex.h"
#include "KeyPad/IKeyPad.h"

#include <functional>


namespace ATE::SM
{
	class KeyPadSM : public OSAL::Task
	{
	public:
		enum State
		{
			State_Idle,
			State_SelectedLetter,
			State_ReleasedLetter,
			State_SelectedNumber,
			State_DetectedPossibleStop,
		};

		enum EventType
		{
			Event_PlaySong = 0,
			Event_StopPlayback
		};

		struct KeyEvent
		{
			char key;
			Device::IKeyPad::KeyState state;

			KeyEvent(char key = '\0', Device::IKeyPad::KeyState state = Device::IKeyPad::KEY_EVENT_NONE)
				: key(key), state(state)
			{

			}
		};

		using Callback_t = std::function<void(EventType event, char letter, char number)>;

		KeyPadSM();
		State GetState();
		void Subscribe(Callback_t cb);

		void Init() override;
		bool Run() override;

	private:
		Device::IKeyPad& KeyPad;
		OSAL::Queue<KeyEvent> EventQueue;

		State state;
		char letter;
		char number;

		Callback_t callback;
		OSAL::Mutex cbMutex;
		OSAL::Mutex stateMutex;

		void SetState(State state);
		bool IsLetter(char c);
		bool IsNumber(char c);

		void Notify(EventType event, char letter = '\0', char number = '\0');

		bool KeyPadCb(char key, Device::IKeyPad::KeyState state);
	};
}

#endif /* INC_SM_KEYPADSM_H_ */
