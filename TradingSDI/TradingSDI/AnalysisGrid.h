#ifndef GROUPWISENETPOS2_HEADER
#define GROUPWISENETPOS2_HEADER
#include "OrderGrid.h"
class GroupWise2NetPos:public CUGCtrl//,public IMTDealSink
{
private:
	DECLARE_MESSAGE_MAP();
public:
	CWinThread* m_pThreads;
	CString str[9];
	void thread_destoy();
	void data_ThreadStart();
	static int Data_Update;
	struct st_Dealing
	{		 		
		wchar_t Group[100];
		wchar_t Symbol[100];
		double preNetqty;
		double Diffqty;
		double Netqty;
		double avg_rate;
		double current_rate;
		double pl;		
		double Total_Amount;	
	};
	typedef TMTArray<st_Dealing> st_Dealing_Array;
	static st_Dealing_Array m_st_Dealing_Array;	
	static st_Dealing_Array m_st_Dealing_Grid_array;
	static st_Dealing_Array m_st_Dealing_Grid_udaptearray;
	static st_Dealing_Array m_st_Dealing_Grid_finalarray;

	static CMutex dealing_mutex;
		

	struct st_shorting
	 {
		wchar_t  m_symbol[200];		
	 };
	typedef TMTArray<st_shorting> st_shortingArray;

	st_shortingArray m_str_array;


	static  int insertFilterFlag;



	BOOL m_bSortedAscending;
	int m_iArrowIndex;
	CUGSortArrowType m_sortArrow;
	int m_iSortCol;
	CFont m_font;
	CUGGridInfo *m_gi;
	//CSocket m_Client;
	GroupWise2NetPos();
	~GroupWise2NetPos();
	void OnSheetSetup(int sheetNumber);	
	virtual void OnSetup();
	//mouse and key strokes
	virtual  int OnCellTypeNotify(long ID,int col,long row,long msg,long param);
	void OnTimer(UINT nIDEvent);
	void OnGetCell(int col,long row,CUGCell *cell);
	void OnMenuCommand(int col,long row,int section,int item);
	virtual int OnDropList(long ID,int col,long row,long msg,long param);
	void filter();
	void addItemToCombobox();
	BOOLEAN  CheckvalueInArray(const CStringArray& arr,CString strval) ;
	void colShorting( int index);
	void InitMenu();
	void gridFilter(int colno,int rows_count,CString col_value);
	void OnTH_LClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed);
};
#endif

