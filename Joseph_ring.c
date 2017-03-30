#include "Joseph_ring.h"

pJoseph CreateJoseph(int n)
{
  int i = 0;
  pJoseph head = NULL;
  pJoseph tail = NULL;
  head = (pJoseph)malloc(sizeof(Joseph));
  head->next = head;
  head->num = 1;
  tail = head;

  printf("create joseph \n");
  for (i = 2;i <=n; i++)
  {
    pJoseph New = (pJoseph)malloc(sizeof(Joseph));
    New->num = i;
    printf("%d",New->num);
// dead circul    
//    New->next = tail->next;//very import, 
//    New->next = New;
//    tail = New;
// reverse
//    New->next = head->next;
//    head->next = New;
//ok
    New->next = tail->next;//very import, 
    tail->next = New;
    tail = New;
  }
  printf(" \n");

  #if 0
  for (i = 1; i < n ; i++){
    
  }
  
  #endif
  return head;
}

void joseph_r(pJoseph head, int k, int m)
{
  assert(head);
  pJoseph cur = NULL;
  pJoseph prev = NULL;
  pJoseph del = NULL;
  cur = head;

  if (k == 1 && m == 1)
  {
    while (cur->next != head)
    {
      printf("%d", cur->num);
      del = cur;
      cur = cur->next;
      free(del);
    }
    printf(" %d\n",cur->num);
  }
  else if (k != 1 && m == 1){
    while (cur->num != k){
      prev = cur;
      cur = cur->next;
    }
    while (head->next != head){
      del = cur;
      prev->next = cur->next;
      cur = cur->next;
      printf("%d", del->num);
      if(cur == head){
        head = cur->next;
      }
      free(del);

      printf(" %d \n",head->num);
    }
  }else
  {
      int i = 0;

        printf("circul  \n");
      while (cur->num != k){
        printf(" %d ",cur->num);
        cur = cur->next;
      }

        printf("circul  \n");
      while (head->next!= head)
      {
        for(i = 1; i < m-1; i++)
	{
	  cur = cur->next;
	}
	del = cur->next;
	cur->next = del->next;
	printf("%d ",del->num);

	if (del == head)
	{
	  head = del->next;
	}
	free(del);
	cur = cur->next;
      }
      printf("%d \n", head->num);

    }
}

void test1()
{
  pJoseph head;
  head = CreateJoseph(10);
  joseph_r(head,1,1);
}

void test2()
{
  pJoseph head;
  head = CreateJoseph(10);
  joseph_r(head,2,1);
}

int main()
{
  pJoseph head;
 // test1();
  //test2();
  head = CreateJoseph(10);
  joseph_r(head,2,2);
//  getchar();
  return 0;
}
