#include "stdafx.h"
#include "avplayer.h"
#include "avplayer_impl.h"

avplayer::avplayer(void)
	: m_impl(new avplayer_impl())
{
}

avplayer::~avplayer(void)
{
	if (m_impl)
		delete m_impl;
}

HWND avplayer::create_window(LPCTSTR player_name)
{
	return m_impl->create_window(player_name);
}

BOOL avplayer::destory_window()
{
	return m_impl->destory_window();
}

BOOL avplayer::subclasswindow(HWND hwnd, BOOL in_process/* = TRUE*/)
{
	return m_impl->subclasswindow(hwnd, in_process);
}

BOOL avplayer::open(LPCTSTR movie, int media_type, int video_out_type/* = 0*/)
{
	return m_impl->open(movie, media_type, video_out_type);
}

BOOL avplayer::play(int index /*= 0*/)
{
	return m_impl->play(index);
}

BOOL avplayer::pause()
{
	return m_impl->pause();
}

BOOL avplayer::resume()
{
	return m_impl->resume();
}

BOOL avplayer::stop()
{
	return m_impl->stop();
}

BOOL avplayer::close()
{
	return m_impl->close();
}

void avplayer::seek_to(double sec)
{
	m_impl->seek_to(sec);
}

BOOL avplayer::full_screen(BOOL fullscreen)
{
	return m_impl->full_screen(fullscreen);
}

double avplayer::curr_play_time()
{
	return m_impl->curr_play_time();
}

double avplayer::duration()
{
	return m_impl->duration();
}

int avplayer::video_width()
{
	return m_impl->video_width();
}

int avplayer::video_height()
{
	return m_impl->video_height();
}

int avplayer::media_count()
{
	return m_impl->play_list().size();
}

int avplayer::query_media_name(int index, char *name, int size)
{
	std::map<std::string, std::string> mlist = m_impl->play_list();
	std::map<std::string, std::string>::iterator finder;
	for (mlist.begin() = finder; finder != mlist.end(); finder++)
	{
		if (index == 0)
		{
			if (finder->second.length() + 1 > size)
				return finder->second.length() + 1;
			strncpy(name, finder->second.c_str(), size);
			return 0;
		}
		index--;
	}
	return -1;
}

HWND avplayer::get_wnd()
{
	return m_impl->GetWnd();
}
