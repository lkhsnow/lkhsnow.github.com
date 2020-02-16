#include "list.h"



struct xLIST		      List_Test;

struct xLIST_ITEM     List_Item1;
struct xLIST_ITEM     List_Item2;
struct xLIST_ITEM     List_Item3;


int main()
{
	
	vListInitialize( &List_Test );
	
	vListInitializeItem( &List_Item1 );
	List_Item1.xItemValue = 1;
	
  vListInitializeItem( &List_Item2 );
	List_Item1.xItemValue = 2;
	
	vListInitializeItem( &List_Item3 );
	List_Item1.xItemValue = 3;
	
	vListInsert( &List_Test, &List_Item2 );
	vListInsert( &List_Test, &List_Item1 );
	vListInsert( &List_Test, &List_Item3 );
	
	for(;;)
	{
		
	}
	
}

