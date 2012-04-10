/****************************************************************************
**
** Author: Miroslav Safr <miroslav.safr@gmail.com>
** Web: https://github.com/safrm/MaxWindow
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
****************************************************************************/

#include <afxwin.h>
#include "MaxWindow.h"

CMyApp myApp;

BOOL CMyApp::InitInstance ()
{
  //dynamic creation of main window
  m_pMainWnd = new CMainWindow;
  //showing window which is not active
  m_pMainWnd->ShowWindow (SW_SHOWNOACTIVATE);
  
  //get current active window handle
  HWND hWnd = GetForegroundWindow();
  //get pointer of active window
  CWnd* pWnd = CWnd::FromHandle(hWnd);

  //is window maximazed??
  BOOL bMaximized = (pWnd->GetStyle() & WS_MAXIMIZE);
 
  if (bMaximized)
    //we restore it 
    pWnd->ShowWindow(SW_SHOWNORMAL);
  else
    //we maximaze it
    pWnd->ShowWindow(SW_MAXIMIZE);

  //close application
  exit(1);
  return TRUE;
}

CMainWindow::CMainWindow ()
{
    Create (NULL, _T ("Maximaze/Restore Active Window"));
}
