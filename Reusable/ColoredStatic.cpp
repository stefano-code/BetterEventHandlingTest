// ColoredStatic.cpp : implementation file
//

#include "stdafx.h"
#include "ColoredStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ColoredStatic

ColoredStatic::ColoredStatic()
{
}

ColoredStatic::~ColoredStatic()
{
}


BEGIN_MESSAGE_MAP(ColoredStatic, CStatic)
	//{{AFX_MSG_MAP(ColoredStatic)
	ON_WM_CTLCOLOR_REFLECT ()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ColoredStatic message handlers


HBRUSH ColoredStatic :: CtlColor( CDC* pDC, UINT nCtlColor )
{
	pDC->SetBkColor( RGB( 255, 255, 255 ) ) ;
	return( (HBRUSH)GetStockObject( WHITE_BRUSH ) ) ;
}
