#include<stdio.h>
 
int main()
{
      int pages[10], page_faults = 0, m, n, s, pno, fno;
      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pno);
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pno; m++)
      {
            printf("Value No. [%d]:\t", m + 1);
            scanf("%d", &pages[m]);
      }
      printf("\nEnter Total Number of Frames:\t");
      {
            scanf("%d", &fno);
      }
      int frames[fno];
      for(m = 0; m < fno; m++)
      {
            frames[m] = -1;
      }
      for(m = 0; m < pno; m++)
      {
            s = 0;
            for(n = 0; n < fno; n++)
            {
                  if(pages[m] == frames[n])
                  {
                        s++;
                        page_faults--;
                  }
            }     
            page_faults++;
            if((page_faults <= fno) && (s == 0))
            {
                  frames[m] = pages[m];
            }   
            else if(s == 0)
            {
                  frames[(page_faults - 1) % fno] = pages[m];
            }
            printf("\n");
            for(n = 0; n < fno; n++)
            {     
                  printf("%d\t", frames[n]);
            }
      } 
      printf("\nTotal Page Faults:\t%d\n", page_faults);
      return 0;
}