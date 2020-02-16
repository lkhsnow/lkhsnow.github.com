
#include "list.h"



void vListInitializeItem( ListItem_t * const pxItem )
{
    pxItem->pvContainer = NULL;
}

void vListInitialize( List_t * const pxList )
{
    pxList->pxIndex             = (ListItem_t *) &( pxList->xListEnd );
    pxList->xListEnd.xItemValue = portMAX_DELAY;
    pxList->xListEnd.pxNext     = ( ListItem_t *)&( pxList->xListEnd );
    pxList->xListEnd.pxPrevious = ( ListItem_t *)&( pxList->xListEnd );
    pxList->uxNumberOfItems     = ( UBaseType_t )0U;
}

void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem )
{
    ListItem_t * const pxIndex = pxList->pxIndex;

    pxNewListItem->pxNext     = pxIndex;
    pxNewListItem->pxPrevious = pxIndex->pxPrevious;

    pxIndex->pxPrevious->pxNext = pxNewListItem;
    pxIndex->pxPrevious         = pxNewListItem;

    pxNewListItem->pvContainer  = (void *)pxList;

    ( pxList->uxNumberOfItems )++;

}

void vListInsert( List_t * const pxList, ListItem_t * const pxNewListItem )
{
    ListItem_t *pxIterator;

    const TickType_t xValueOfInsertion = pxNewListItem->xItemValue;

    if( xValueOfInsertion == portMAX_DELAY )
    {
        pxIterator = pxList->xListEnd.pxPrevious;
    }
    else
    {
        for( pxIterator = ( ListItem_t *)&(pxList->xListEnd);
            pxIterator->pxNext->xItemValue <= xValueOfInsertion;
            pxIterator = pxIterator->pxNext )
            {

            }
    }
    

    pxNewListItem->pxNext = pxIterator->pxNext;
    pxNewListItem->pxNext->pxPrevious = pxNewListItem;
    pxNewListItem->pxPrevious = pxIterator;
    pxIterator->pxNext = pxNewListItem;

    pxNewListItem->pvContainer = (void*)pxList;
    (pxList->uxNumberOfItems)++;

}

UBaseType_t uxListRemove( ListItem_t * const pxItemToRemove )
{
    List_t * const pxLixt = (List_t*)pxItemToRemove->pvContainer;

    pxItemToRemove->pxNext->pxNext     = pxItemToRemove->pxPrevious;
    pxItemToRemove->pxPrevious->pxNext = pxItemToRemove->pxNext;

    if( pxLixt->pxIndex == pxItemToRemove )
    {
        pxLixt->pxIndex = pxItemToRemove->pxPrevious;
    }

    pxItemToRemove->pvContainer = NULL;

    (pxLixt->uxNumberOfItems)--;

    return pxLixt->uxNumberOfItems;

}


