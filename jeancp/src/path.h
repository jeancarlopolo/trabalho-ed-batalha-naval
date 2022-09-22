#ifndef PATH__
#define PATH__

/*
   Este modulo prove funcoes para manipulacao de caminhos de arquivos.
   Basicamente, exitem 2 tipos de funcoes:

      - separam caminho em seus componentes: splitPath, getFileName, getPath
      - constroem caminho a partir de seus componentes: joinFilePath,
          joinAll, normalizePath.

   Um caminho completo (fullPath) compreende uma sequencia de subdiretorios(path),
   o nome do arquivo e sua extensao.
   O caminho (path) e� toda a subcadeia que esta' esquerda do ultimo separador �/�,
   incluindo-o. A extensao � a subcadeia que esta' `a direita do ultimo
   separador '.', incluindo-o. O nome do arquivo � a subcadeia que esta� entre
   estes dois �ltimos.

   Nesta operacoes, um caminho vazio ou um componente vazio e� representado
   por uma string vazia.
  Os resultados das operacoes sao atribuidos a paramentros da funcao.
  Este parametros sao vetores de caracteres pre-alocados. A cada um destes
  parametros, existe um respectivo parametro que indica seu tamanho (em caracteres).

 */

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq);
/*
    Dado um caminho (fullPath), copia cada um de seus componentes
    nos parametros path (caminho do arquivo), nomeArq (nome do arquivo, sem
    seu path e sem sua extensao) e extArq (extensao do arquivo).
    Estes parametros sao vetores de tamanhos, respectivamente, lenPath,
    lenNomeArq e lenExtArq. Exemplos:

    fullPath               path        nomeArqq   extArq
    =====================================================
    "aaa/bbb/ccc.txt" =>   "aaa/bbb"   "ccc"      ".txt"
    "ccc.txt"         =>   ""          "ccc"      ".txt"
    ".txt"            =>   ""          ""         ".txt"
    "ccc.ddd.txt"     =>   ""          "ccc.ddd"  ".txt"
    "ccc"             =>   ""          "ccc"      ""
 */

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath);
/*
  Dado um caminho (path) e um nome de arquivo (possivelmente, com sua extensao),
  copia para fullPath o caminho completo do arquivo. Exemplos:

   path         fileName =>  fullPath
   =============================================
   "aaa/bbb"    "c.txt"  =>  "aaa/bbb/c.txt"
   "aaa/bbb/"   "c.txt"  =>  "aaa/bbb/c.txt"
   ""           "c.txt"  =>  "c.txt"
   "aaa/bbb"    "c"      =>  "aaa/bbb/c"
 */

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenFullPath);
/*
   Semelhante a joinFilePath, porem, a extensao do arquivo e� informado explicitamente
   pelo parametro ext. Exemplos:

   path       fileName  ext     => fullPath
   =================================================
   "aaa/bbb"  "ccc"     ".txt"  => "aaa/bbb/ccc.txt"
   "aaa/bbb/  "ccc"     ".txt"  => "aaa/bbb/ccc.txt"
   ""         "ccc"     ".txt"  => "ccc.txt"
   "aaa/bbb"  "ccc"     ""      => "aaa/bbb/ccc"
 */

void getFileName(char *fullPath, char *fileName, int lenFileName);
/*
    Dado um caminho completo (fullPath), copia em fileName o nome do arquivo
    (possivelmente) com sua extensao. Exemplos:

    fullPath          => fileName
    ==============================
    "aaa/bb/cc.txt"   => "cc.txt"
    "cc.txt"          => "cc.txt"
    "cc."             => "cc."
    "cc"              => "cc"
    ".txt"            => ".txt"
 */

void getPath(char *fullPath, char *path, int lenPath);
/*
   Dado um caminho completo, retorna seu respectivo path.

   fullPath           => path
   ================================
   "aaa/bbb/ccc.txt"  => "aab/bbb"
   "ccc.txt"          => ""
   "aaa/bbb/ccc"      => "aaa/bbb"
 */

void normalizePath(char *path, char *normPath, int lenNormPath);
/*
   Dado um caminho (path), (supostamente) sem nome de arquivo,
   copia em normPath o caminho, sem o separador do final (se existir).

   path         => normPath
   ==========================
   "aa/bb/cc"   => "aa/bb/cc"
   "aa/bb/cc/"  => "aa/bb/cc"
 */

#endif
