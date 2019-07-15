/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IKeyPad.h
 * Brief: Interface definition for they KeyPad device
 * Module: Device
 */

#ifndef ATE_KEYPAD_H_
#define ATE_KEYPAD_H_

#include <functional>
#include "OS/UniqueLock.h"

namespace ATE::Device
{
	class IKeyPad
	{
	public:
		enum KeyState
		{
			KEY_EVENT_NONE = 0,
			KEY_RELEASED,
			KEY_PRESSED,
		};

		using KeyChangedCallback = std::function<bool(char key, KeyState state)>;

		void Subscribe(const KeyChangedCallback& cb)
		{
			OSAL::UniqueLock lock(cbMutex);
			this->cb = cb;
		}

	protected:
		bool Notify(char key, KeyState state)
		{
			OSAL::UniqueLock lock(cbMutex);
			if (cb != nullptr)
			{
				return cb(key, state);
			}
			return false;
		}

	private:
		KeyChangedCallback cb;
		OSAL::Mutex cbMutex;
	};
}

#endif /* ATE_KEYPAD_H_ */
