#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (void)
{
  //dichiarazione delle variabili
  char m[128];
  char k[128];
  int lun_m;
  int lun_k;
  int percorso;
  time_t tempo;
  char txt_cifrato[128];
  int x;
  printf("inserisci il testo da crifrare: ");
  fgets(m, 128, stdin);
  lun_m = strlen(m)-1;
  printf("La stringa m è lunga %d caratteri\n\n", lun_m);
  //scelta del percorso
  printf("Ora digiti 1 per inserire la chaive manualmente. Oppure digiti 2 per generarla in modo casuale. Qualsiasi altro numero non sarà accettato.\n");
  scanf("%d", &percorso);
  while(percorso==0 || percorso>2) //La scelta deve essere per forza 1 o 2
  {
    scanf("%d",&percorso);
    while(getchar() != '\n');
  }
  switch(percorso) //inizio switch
  {
    case 1: //inizio case 1
           printf("Inserisci la chiave k\n");
           getchar();
           fgets(k, 128, stdin);
           lun_k = strlen(k)-1;
           while(lun_k < lun_m)
             {
               printf("La chiave k digitata è troppo corta. Inserire una chiave di lunghezza maggiore o uguale ad m\n");
               fgets(k, 128, stdin);
               lun_k = strlen(k)-1;
             }
           printf("La chiave k è lunga %d caratteri\n\n", lun_k);
           printf("Il messaggio cifrato è: ");
           for(x=0; x<=lun_m; x++)
              {
                txt_cifrato[x] = m[x] ^ k[x]; //XOR fra m e k
                printf("%d", txt_cifrato[x]);
              }
              printf("\n");
            printf("Il messaggio originale è: ");
            for(x=0; x<=lun_m; x++)
            {
              m[x] = k[x] ^ txt_cifrato[x]; //XOR fra k e testo cifrato
              printf("%c", m[x]);
            }
           break; //fine case 1
    case 2: //inizio case 2
           for(int i = 0; i < lun_m; i++)
           {
             //genero un numero random e lo assegno a k
             srand((unsigned) time(&tempo));
             k[i]=97+rand() %25;
             printf("%c", k[i]);
           }
           printf("\n");
           printf("Il messaggio cifrato è: ");
           for(x=0; x<=lun_m; x++)
              {
                txt_cifrato[x] = m[x] ^ k[x];
                printf("%d", txt_cifrato[x]);
              }
              printf("\n");
            printf("Il messaggio originale è: ");
            for(x=0; x<=lun_m; x++)
            {
              m[x] = k[x] ^ txt_cifrato[x];
              printf("%c", m[x]);
            }

          break; //fine case 2
    default:
    break;
  } //fine switch
  return 0;
}
