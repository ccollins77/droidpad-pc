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
#ifndef _HELP_H
#define _HELP_H

#include <wx/html/htmlwin.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>

// Hack around constness of OnOpeningUrl
class HelpWindow;
extern HelpWindow *currentWindow;

class HelpWindow : public wxHtmlWindow {
	public:
		inline HelpWindow(wxWindow *parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxHW_DEFAULT_STYLE, const wxString& name = wxT("helpWindow")) :
			wxHtmlWindow(parent, id, pos, size, style, name)
		{
			currentWindow = this;
		}
		virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType type,const wxString& url, wxString *redirect) const;
};

class Help : public wxFrame {
	public:
		Help();
		virtual inline ~Help() { };
		DECLARE_EVENT_TABLE()
	public:
	protected:
		HelpWindow *web;
		void OnClose(wxCloseEvent& event);
};

#endif
