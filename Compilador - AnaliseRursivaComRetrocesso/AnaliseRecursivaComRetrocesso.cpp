/* OBJETIVO (15/05/2012)

*Professor - � uma tentativa de construir uma arvore de deriva��o a parti das folhas produzindo uma deriva��o mais a direita ao reverso.
*Livro - A an�lise redutiva de uma senten�a (ou programa) pode ser vista como a tentativa de
constmir uma �rvore de deriva��o a partir das folhas, produzindo uma denva��o mais �
direita ao reverso. A denomina��o redutiva refere-se ao processo que sofre a senten�a de
entrada. a qual � reduzida at� ser atingido o s�mbolo inicial da gram�tica (raiz da �rvore de
deriva��o). D�-se o nome de red~r��o � opera��o de substitui��o do lado direito de uma
produ��o pelo n�c-terminal correspondente (lado esquerdo).
Pagina 40 do livro (Imprementa��o de linguagen  de Programa��o)
Exemplo 3.7 - Analizador recursivo com Retrocesso
Analizador sintatico
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

char token;

//prototipos
int nextChar(); //Indice de fun��es ou procedimentos
int L();
int S();//Simbolo n�o terminal
// w = { aa, [a, a], a; } palavras, o sintatito reconhece se a pavalra reconhece ou nao, palavra inteira
//palavra existe pelo analizador lexico!


//programa Principal
int main()
{             
    printf("Digite o texto e finaliza pelo caractere ENTER: ");          
    token=nextChar(); 	//Ele consome caracter da frase at� ela acabar 
			//Ler o primeiro simbolo da sua frase, simbilo inicial (mada para S)
     if(S())
       if(token == '$') printf("\nSucesso "); //Se ele conseguir chegar no final da palavra, sucesso!
       else printf("\nERRO "); 
    else printf("\nERRO "); //Se ele n�o conseguir achar o simbolo inicial, aparece erro!

   printf("\n\nAperte algo para continuar ");
   getch();                
   return 0;
}    


/* l� pr�ximo caracter da entrada */      
int nextChar()           
   {
   getchar();
   }       

//Arvorde de deriva�ao
int L()
  {
  if(S())
    if(token == ';')
       {
       token=nextChar();
       if(L())     
          return 1;
       else return 0;
       }
   else return 1; 
 else return 0; 
}

//Marcacao de ponto para retrocesso
int S()
  {
  if(token == 'a')
   {
   token=nextChar();
   return 1;
   }
  else if(token == '[')
         {
         token=nextChar();
         if(L())     
          {
            if(token == ']')
            {
            token=nextChar();
            return 1;
            }
            else return 0;
         }
        else return 0;
        }
   else return 0; 
}
