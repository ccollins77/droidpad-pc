/*
 * This file is part of DroidPad.
 * DroidPad lets you use an Android mobile to control a joystick or mouse
 * on a Windows or Linux computer.
 *
 * DroidPad is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DroidPad is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DroidPad, in the file COPYING.
 * If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DP_CALLBACKS_H
#define DP_CALLBACKS_H

#include <wx/string.h>
#include <wx/clntdata.h>
#include <vector>
#include <stdint.h>

#include "events.hpp"

#define DEVICE_USB 1
#define DEVICE_NET 2
#define DEVICE_CUSTOMHOST 3

namespace droidpad {
	class AndroidDevice : public wxClientData {
		public:
			int type;

			wxString usbId;
			wxString ip;
			uint16_t port;
			uint16_t securePort;
			wxString name;

			// If TLS connections are supported
			bool secureSupported;

			operator wxString() const;
			bool operator ==(const AndroidDevice& b);
			AndroidDevice(const AndroidDevice& dev);
			AndroidDevice();
	};

	typedef std::vector<AndroidDevice> AndroidDeviceList;

	class UpdateInfo {
		public:
			int versionCode;
			wxString versionName;
			wxString url;
			int bytesTotal;
			wxString name;
			wxString comment;
			wxString md5;
	};

	// Callback system between the UI and the backend code. This is implemented by whichever UI is being used.
	class DroidPadCallbacks
	{
		public:
			virtual ~DroidPadCallbacks();
			virtual void dpInitComplete(bool complete) = 0;
			virtual void dpCloseComplete() = 0;

			virtual void dpNewDeviceList(AndroidDeviceList &list) = 0;

			virtual void threadStarted() = 0;
			virtual void threadError(wxString failReason) = 0;
			virtual void threadInfoBox(wxString infoMessage) = 0;
			virtual void setStatusText(wxString text, bool showSpinner = false) = 0;
			virtual void threadStopped() = 0;

			virtual void updatesAvailable(std::vector<UpdateInfo> updates, std::vector<UpdateInfo> latest, bool userRequest) = 0;

			virtual void updateStarted() = 0;
			virtual void updateProgress(int bytesDone, int bytesTotal) = 0;
			virtual void updateFailed() = 0;
			virtual void updateCompleted(bool wasCancel = false) = 0;

			/**
			 * Asks the user for any necessary customisations for a device.
			 * Currently, only type == DEVICE_CUSTOMHOST should be used.
			 */
			virtual bool customiseDevice(AndroidDevice *device) = 0;
	};
};

#endif
