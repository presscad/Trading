#pragma once
#ifndef CodesChanged_HEADER
#define CodesChanged_HEADER
#include "OrderGrid.h"
#include "ugctrl.h"
class CCodesChanged :public CUGCtrl
{
private:
	DECLARE_MESSAGE_MAP();

public:
	CCodesChanged(void);
	~CCodesChanged(void);

public:
	CWinThread* m_pThreads;
	CString str[18];

	static int col_click;
	static int a_d;

	struct st_Dealing
	{		 		
		wchar_t Section[100];
		wchar_t Login[100];
		double Order;
		wchar_t Order_In_Time[50];
		int Deal;
		wchar_t Symbol[100];
		wchar_t Type1[100];
		double Volume;		
		double Price;
		wchar_t Comment[100];
		wchar_t Status[100];
        wchar_t Opposite_Deal[100];
		wchar_t Deal_Time[100];
	    wchar_t Symbol1[100];
		wchar_t Type[100];
		double Volume1;
		double Price1;
		wchar_t Status1[100];
	};
	typedef TMTArray<st_Dealing> st_Dealing_Array;
	static st_Dealing_Array m_st_Dealing_Array;	
	static st_Dealing_Array m_st_Dealing_Grid_array;	
	static CMutex dealing_mutex;
		

	static  int insertFilterFlag;

	static CString col0_val,col1_val,col2_val,col3_val,col4_val,col5_val,col6_val,col7_val,col8_val,col9_val,col10_val,col11_val,col12_val,col13_val,col14_val,col15_val,col16_val,col17_val;
	int	m_nSpinIndex;
	static  int Data_Update;
public:
	BOOL m_bSortedAscending;
	int m_iArrowIndex;
	CUGSortArrowType m_sortArrow;
	int m_iSortCol;
	CFont m_font;
	CUGGridInfo *m_gi;
	void OnSheetSetup(int sheetNumber);	
	virtual void OnSetup();
	void OnTimer(UINT nIDEvent);
	void OnGetCell(int col,long row,CUGCell *cell);
	void OnMenuCommand(int col,long row,int section,int item);
	void filter();
	void addItemToCombobox();
	BOOLEAN  CheckvalueInArray(const CStringArray& arr,CString strval) ;
	void InitMenu();
	void data_ThreadStart();
	void thread_destoy();
	void gridFilter(int colno,int rows_count,CString col_value);
	void OnTH_LClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed);
	virtual int OnDropList(long ID,int col,long row,long msg,long param);
	virtual int OnEditFinish(int col, long row,CWnd *edit,LPCTSTR string,BOOL cancelFlag);
	virtual void OnDClicked(int col,long row,RECT *rect,POINT *point,BOOL processed);
	//mouse and key strokes
	virtual  int OnCellTypeNotify(long ID,int col,long row,long msg,long param);
};
#endif
