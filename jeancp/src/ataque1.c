#include "ataque1.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/* O barco é  movimentado, atinge uma mina flutuante e é imediatamente destruído.
 A movimentação se dá em 2 fases: seleção das embarcações passíveis de movimentação 
 e a efetiva movimentação de um dos barcos previamente selecionados. 
Algumas das naus selecionadas são designadas como naus-capitãs. 
É movimentado um barco que está em uma posição relativa a uma das naus-capitãs. 
Podem exisitir no máximo 10 naus-capitãs
*/

typedef struct ataque1{
    char id;
    Lista nauscap;
    Lista movimentacao;
}ataque1;





