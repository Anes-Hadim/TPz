  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

   
  /* 
       --------------------------------------------- 
      */

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include<conio.h>
  #include<windows.h>

  typedef int bool ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tib Type_Tib  ;
  typedef Type_Tib * Typestr_Tib ;
  typedef int Type1_Tib  ;
  typedef bool Type2_Tib  ;
  struct Tib
    {
      Type1_Tib Champ1 ;
      Type2_Tib Champ2 ;
    };

  Type1_Tib Struct1_Tib ( Typestr_Tib S)
    {
      return  S->Champ1 ;
    }

  Type2_Tib Struct2_Tib ( Typestr_Tib S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tib ( Typestr_Tib S, Type1_Tib Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Tib ( Typestr_Tib S, Type2_Tib Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tib Typeelem_ATib   ;
  typedef struct Noeud_ATib * Pointeur_ATib ;

  struct Noeud_ATib
    {
      Typeelem_ATib  Val ;
      Pointeur_ATib Fg ;
      Pointeur_ATib Fd ;
      Pointeur_ATib Pere ;
     } ;

  Typeelem_ATib Info_ATib( Pointeur_ATib P )
    { return P->Val;   }

  Pointeur_ATib Fg_ATib( Pointeur_ATib P)
    { return P->Fg ; }

  Pointeur_ATib Fd_ATib( Pointeur_ATib P)
    { return P->Fd ; }

  Pointeur_ATib Pere_ATib( Pointeur_ATib P)
    { return P->Pere ; }

  void Aff_info_ATib ( Pointeur_ATib P, Typeelem_ATib Val)
    {
      Typeelem_ATib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATib( Pointeur_ATib P, Pointeur_ATib Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATib( Pointeur_ATib *P)
    {
      *P = (struct Noeud_ATib *) malloc( sizeof( struct Noeud_ATib))   ;
      (*P)->Val = malloc(sizeof(Type_Tib));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATib( Pointeur_ATib P)
    { free( P ) ; }


  /** Implémentation **\: LISTE DE ENTIERS**/

  /** Listes lin?aires cha?n?es **/

  typedef int Typeelem_Li   ;
  typedef struct Maillon_Li * Pointeur_Li ;

  struct Maillon_Li
    {
      Typeelem_Li  Val ;
      Pointeur_Li Suiv ;
    } ;

  Pointeur_Li Allouer_Li (Pointeur_Li *P)
    {
      *P = (struct Maillon_Li *) malloc( sizeof( struct Maillon_Li)) ;
      (*P)->Suiv = NULL;
    }

  void Aff_val_Li(Pointeur_Li P, Typeelem_Li Val)
    {
      P->Val = Val ;
    }

  void Aff_adr_Li( Pointeur_Li P,  Pointeur_Li Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_Li Suivant_Li(  Pointeur_Li P)
    { return( P->Suiv ) ;  }

  Typeelem_Li Valeur_Li( Pointeur_Li P)
    { return( P->Val) ; }

  void Liberer_Li ( Pointeur_Li P)
    { free (P);}


  /** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Piles **/

  typedef Pointeur_ATib Typeelem_PATib ;
  typedef struct Maillon_PATib * Pointeur_PATib ;
  typedef   Pointeur_PATib  Typepile_PATib  ;

  struct Maillon_PATib
    {
      Typeelem_PATib  Val ;
      Pointeur_PATib Suiv ;
    } ;

  void Creerpile_PATib( Pointeur_PATib *P )
    { *P = NULL ; }

  bool Pilevide_PATib ( Pointeur_PATib P )
    { return  (P == NULL ); }

  void Empiler_PATib ( Pointeur_PATib *P,  Typeelem_PATib Val )
    {
      Pointeur_PATib Q;

      Q = (struct Maillon_PATib *) malloc( sizeof( struct Maillon_PATib))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PATib ( Pointeur_PATib *P,  Typeelem_PATib *Val )
    {
      Pointeur_PATib Sauv;

      if (! Pilevide_PATib (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implémentation **\: LISTE DE ARBRES BINAIRES DE STRUCTURES**/

  /** Listes lin?aires cha?n?es **/

  typedef Pointeur_ATib Typeelem_LATib   ;
  typedef struct Maillon_LATib * Pointeur_LATib ;

  struct Maillon_LATib
    {
      Typeelem_LATib  Val ;
      Pointeur_LATib Suiv ;
    } ;

  Pointeur_LATib Allouer_LATib (Pointeur_LATib *P)
    {
      *P = (struct Maillon_LATib *) malloc( sizeof( struct Maillon_LATib)) ;
      (*P)->Suiv = NULL;
    }

  void Aff_val_LATib(Pointeur_LATib P, Typeelem_LATib Val)
    {
      P->Val = Val ;
    }

  void Aff_adr_LATib( Pointeur_LATib P,  Pointeur_LATib Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_LATib Suivant_LATib(  Pointeur_LATib P)
    { return( P->Suiv ) ;  }

  Typeelem_LATib Valeur_LATib( Pointeur_LATib P)
    { return( P->Val) ; }

  void Liberer_LATib ( Pointeur_LATib P)
    { free (P);}

  /** Variables du programme principal **/
  Pointeur_ATib R=NULL;
  Pointeur_ATib R_copy=NULL;
  Typestr_Tib S;
  bool Inserer;
  bool Is_search;
  int Val;
  int I;
  int J;
  int N;
  int M;
  Pointeur_Li Trav1=NULL;
  Pointeur_Li Trav2=NULL;
  Pointeur_Li Trav3=NULL;
  Pointeur_Li Trav4=NULL;
  Pointeur_Li Verif1=NULL;
  Pointeur_Li Verif2=NULL;
  Pointeur_Li Verif3=NULL;
  Pointeur_Li Verif4=NULL;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Initialisation d'une structure **/
  void Init_struct_Tib ( Typestr_Tib S, Type_Tib S_ )
    {
      S->Champ1 = S_.Champ1 ;
      S->Champ2 = S_.Champ2 ;
    }


  /** Prototypes des fonctions **/

  void Print_liste (Pointeur_Li *Tete);
  Pointeur_ATib Insertion (Pointeur_ATib *Noed , int *Val , bool *Ins) ;
  bool  Feuille (Pointeur_ATib *Noed) ;
  void Inordre (Pointeur_ATib *Noed);
  void List_inordre (Pointeur_ATib *N , Pointeur_Li *Head , Pointeur_Li *Tail);
  bool  Verifier_arb (Pointeur_ATib *Noeud) ;
  void Iter_stack (Pointeur_PATib *P , Pointeur_Li *Trav , Pointeur_Li *Tail);
  Pointeur_Li Verif_branche_g (Pointeur_ATib *R) ;
  Pointeur_Li Verif_branche_d (Pointeur_ATib *R) ;
  void Clear_visited (Pointeur_ATib *R);
  bool  Children_visited (Pointeur_ATib *R) ;
  void Trav_leaf_gauche (Pointeur_ATib *R , Pointeur_Li *Trav2 , Pointeur_Li *Tail);
  Pointeur_Li Leaf_gauche (Pointeur_ATib *R) ;
  void Trav_leaf_droite (Pointeur_ATib *R , Pointeur_Li *Trav4 , Pointeur_Li *Tail);
  Pointeur_Li Leaf_droite (Pointeur_ATib *R) ;
  bool  Comparer_listes (Pointeur_Li *Temp1 , Pointeur_Li *Temp2) ;
  Pointeur_ATib Verif_leaf_trav_g (Pointeur_ATib *N , Pointeur_Li *Verif2 , Pointeur_Li *Tail) ;
  Pointeur_Li Verif_leaf_g (Pointeur_ATib *N) ;
  Pointeur_ATib Verif_leaf_trav_d (Pointeur_ATib *N , Pointeur_Li *Verif2 , Pointeur_Li *Tail) ;
  Pointeur_Li Verif_leaf_d (Pointeur_ATib *N) ;
  void Liste_preordre_g (Pointeur_ATib *N , Pointeur_LATib *Head , Pointeur_LATib *Tail);
  Pointeur_Li Branche_gauche (Pointeur_ATib *N) ;
  void Liste_preordre_d (Pointeur_ATib *N , Pointeur_LATib *Head , Pointeur_LATib *Tail);
  Pointeur_Li Branche_droite (Pointeur_ATib *N) ;
  void Affiche_tout (Pointeur_ATib *R , Pointeur_ATib *R_copy);
  void Affiche_resume (Pointeur_ATib *R , Pointeur_ATib *R_copy);

  /*--------------------------------------------------------------------*/
  void Print_liste (Pointeur_Li *Tete)
    {
      /** Variables locales **/
      Pointeur_Li Temp=NULL;

      /** Corps du module **/
     Temp  =  *Tete ;
     while( Temp != NULL) {
       printf ( " %d", Valeur_Li(Temp) ) ;
       Temp  =  Suivant_Li ( Temp ) ;
      
     }
    }
  /*--------------------------------------------------------------------*/
  Pointeur_ATib Insertion (Pointeur_ATib *Noed , int *Val , bool *Ins) 
    {
      /** Variables locales **/
      Pointeur_ATib Insertion2 =NULL;
      Pointeur_ATib N=NULL;
      Typestr_Tib S;
      Type_Tib S_S;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     if( *Noed == NULL) {
       S_S.Champ1 = *Val ;
       S_S.Champ2 = False ;
       Init_struct_Tib ( S , S_S )  ;
       Creernoeud_ATib (& N ) ;
       Aff_info_ATib ( N , S ) ;
       *Ins  =  True ;
       *Noed  =  N ;
       }
     else
       {
      /* Affectation globale de structure */
       S->Champ1 =   Info_ATib ( *Noed )->Champ1;
       S->Champ2 =   Info_ATib ( *Noed )->Champ2;
 ;
       if( *Val < Struct1_Tib ( S  )) {
         _Px1 =  Fg_ATib ( *Noed ) ;
         Aff_fg_ATib ( *Noed , Insertion ( &_Px1, & *Val , & *Ins ) ) ;
         }
       else
         {
         if( *Val > Struct1_Tib ( S  )) {
           _Px2 =  Fd_ATib ( *Noed ) ;
           Aff_fd_ATib ( *Noed , Insertion ( &_Px2, & *Val , & *Ins ) ) ;
           }
         else
           {
           *Ins  =  False ;
          
         }
       }
     } ;
     Insertion2  =  *Noed ;
    
     return Insertion2 ;
    }
  /*--------------------------------------------------------------------*/
  bool  Feuille (Pointeur_ATib *Noed) 
    {
      /** Variables locales **/
      bool  Feuille2 ;

      /** Corps du module **/
     if( ( ( Fg_ATib ( *Noed ) == NULL ) && ( Fd_ATib ( *Noed ) == NULL ) ))   {
       Feuille2  =  True ;
       }
     else
       {
       Feuille2  =  False ;
      
     }
     return Feuille2 ;
    }
  /*--------------------------------------------------------------------*/
  void Inordre (Pointeur_ATib *Noed)
    {
      /** Variables locales **/
      Typestr_Tib S;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     if( *Noed != NULL) {
       _Px1 =  Fg_ATib ( *Noed ) ;
       Inordre ( &_Px1) ;
      /* Affectation globale de structure */
       S->Champ1 =   Info_ATib ( *Noed )->Champ1;
       S->Champ2 =   Info_ATib ( *Noed )->Champ2;
 ;
       printf ( " %d", Struct1_Tib(S) ) ;
       _Px2 =  Fd_ATib ( *Noed ) ;
       Inordre ( &_Px2) ;
      
     }
    }
  /*--------------------------------------------------------------------*/
  void List_inordre (Pointeur_ATib *N , Pointeur_Li *Head , Pointeur_Li *Tail)
    {
      /** Variables locales **/
      Pointeur_Li Maillon=NULL;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *N != NULL) {
       _Px1 =  Fg_ATib ( *N ) ;
       List_inordre ( &_Px1, & *Head , & *Tail ) ;
       Allouer_Li (& Maillon ) ;
       Aff_val_Li ( Maillon , Struct1_Tib ( Info_ATib ( *N )  ) ) ;
       Aff_adr_Li ( Maillon , NULL ) ;
       if( *Head == NULL) {
         *Head  =  Maillon ;
         *Tail  =  *Head ;
         }
       else
         {
         Aff_adr_Li ( *Tail , Maillon ) ;
         *Tail  =  Maillon ;
        
       } ;
       _Px2 =  Fd_ATib ( *N ) ;
       List_inordre ( &_Px2, & *Head , & *Tail ) ;
      
     }
    }
  /*--------------------------------------------------------------------*/
  bool  Verifier_arb (Pointeur_ATib *Noeud) 
    {
      /** Variables locales **/
      bool  Verifier_arb2 ;
      Pointeur_ATib Temp=NULL;
      Pointeur_Li Head=NULL;
      Pointeur_Li Tail=NULL;
      Pointeur_Li Next=NULL;
      bool Error;

      /** Corps du module **/
     Head  =  NULL ;
     Tail  =  NULL ;
     Temp  =  *Noeud ;
     List_inordre ( & Temp , & Head , & Tail ) ;
     Error  =  False ;
     while( ( ( Head != NULL ) && ( Error == False ) ))  {
       Next  =  Suivant_Li ( Head ) ;
       if( Next != NULL) {
         if( Valeur_Li ( Head ) >= Valeur_Li ( Next ))   {
           Error  =  True ;
          
         }
       } ;
       Head  =  Suivant_Li ( Head ) ;
      
     } ;
     Verifier_arb2  =  ! Error ;
    
     return Verifier_arb2 ;
    }
  /*--------------------------------------------------------------------*/
  void Iter_stack (Pointeur_PATib *P , Pointeur_Li *Trav , Pointeur_Li *Tail)
    {
      /** Variables locales **/
      Pointeur_PATib Temp=NULL;
      Pointeur_Li Maillon=NULL;
      Pointeur_ATib N=NULL;
      Typestr_Tib S;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     Creerpile_PATib (& Temp ) ;
     while( Pilevide_PATib ( *P ) == False) {
       Depiler_PATib (& *P , &N ) ;
      /* Affectation globale de structure */
       S->Champ1 =   Info_ATib ( N )->Champ1;
       S->Champ2 =   Info_ATib ( N )->Champ2;
 ;
       if( Struct2_Tib ( S  ) == False) {
         Aff_struct2_Tib ( S  , True ) ;
         Aff_info_ATib ( N , S ) ;
         Allouer_Li (& Maillon ) ;
         Aff_val_Li ( Maillon , Struct1_Tib ( S  ) ) ;
         Aff_adr_Li ( Maillon , NULL ) ;
         if( *Trav == NULL) {
           *Trav  =  Maillon ;
           *Tail  =  *Trav ;
           }
         else
           {
           Aff_adr_Li ( *Tail , Maillon ) ;
           *Tail  =  Maillon ;
          
         }
       } ;
       Empiler_PATib (& Temp , N ) ;
      
     } ;
     while( Pilevide_PATib ( Temp ) == False) {
       Depiler_PATib (& Temp , &N ) ;
       Empiler_PATib (& *P , N ) ;
      
     }
    }
  /*--------------------------------------------------------------------*/
  Pointeur_Li Verif_branche_g (Pointeur_ATib *R) 
    {
      /** Variables locales **/
      Pointeur_Li Verif_branche_g2 =NULL;
      Pointeur_ATib N=NULL;
      Pointeur_PATib P=NULL;
      Pointeur_Li Trav1=NULL;
      Pointeur_Li Tail=NULL;

      /** Corps du module **/
     N  =  *R ;
     Trav1  =  NULL ;
     Tail  =  NULL ;
     if( N != NULL) {
       Creerpile_PATib (& P ) ;
       while( ( ( Pilevide_PATib ( P ) == False ) || ( N != NULL ) ))  {
         while( N != NULL)  {
           Empiler_PATib (& P , N ) ;
           if( ( ( Fg_ATib ( N ) == NULL ) && ( Fd_ATib ( N ) != NULL ) ))   {
             N  =  Fd_ATib ( N ) ;
             Empiler_PATib (& P , N ) ;
             }
           else
             {
             N  =  Fg_ATib ( N ) ;
            
           }
         } ;
        /* inserer les noueds trouver dans la pile dans la liste*/
        /* utiliser visited pour eviter la repitision*/
         Iter_stack ( & P , & Trav1 , & Tail ) ;
         Depiler_PATib (& P , &N ) ;
         N  =  Fd_ATib ( N ) ;
        
       }
     } ;
     Verif_branche_g2  =  Trav1 ;
    
     return Verif_branche_g2 ;
    }
  /*--------------------------------------------------------------------*/
  Pointeur_Li Verif_branche_d (Pointeur_ATib *R) 
    {
      /** Variables locales **/
      Pointeur_Li Verif_branche_d2 =NULL;
      Pointeur_ATib N=NULL;
      Pointeur_PATib P=NULL;
      Pointeur_Li Trav3=NULL;
      Pointeur_Li Tail=NULL;

      /** Corps du module **/
     N  =  *R ;
     Trav3  =  NULL ;
     Tail  =  NULL ;
     if( N != NULL) {
       Creerpile_PATib (& P ) ;
       while( ( ( Pilevide_PATib ( P ) == False ) || ( N != NULL ) ))  {
         while( N != NULL)  {
           Empiler_PATib (& P , N ) ;
           if( ( ( Fd_ATib ( N ) == NULL ) && ( Fg_ATib ( N ) != NULL ) ))   {
             N  =  Fg_ATib ( N ) ;
             Empiler_PATib (& P , N ) ;
             }
           else
             {
             N  =  Fd_ATib ( N ) ;
            
           }
         } ;
        /* inserer les noueds trouver dans la pile dans la liste*/
        /* utiliser visited pour eviter la repitision*/
         Iter_stack ( & P , & Trav3 , & Tail ) ;
         Depiler_PATib (& P , &N ) ;
         N  =  Fg_ATib ( N ) ;
        
       }
     } ;
     Verif_branche_d2  =  Trav3 ;
    
     return Verif_branche_d2 ;
    }
  /*--------------------------------------------------------------------*/
  void Clear_visited (Pointeur_ATib *R)
    {
      /** Variables locales **/
      Typestr_Tib S;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     if( *R != NULL) {
       _Px1 =  Fg_ATib ( *R ) ;
       Clear_visited ( &_Px1) ;
       _Px2 =  Fd_ATib ( *R ) ;
       Clear_visited ( &_Px2) ;
      /* Affectation globale de structure */
       S->Champ1 =   Info_ATib ( *R )->Champ1;
       S->Champ2 =   Info_ATib ( *R )->Champ2;
 ;
       Aff_struct2_Tib ( S  , False ) ;
       Aff_info_ATib ( *R , S ) ;
      
     }
    }
  /*--------------------------------------------------------------------*/
  bool  Children_visited (Pointeur_ATib *R) 
    {
      /** Variables locales **/
      bool  Children_visited2 ;

      /** Corps du module **/
     if( Feuille ( & *R ) == True) {
       Children_visited2  =  True ;
       }
     else
       {
       if( ( ( Fg_ATib ( *R ) != NULL ) && ( Fd_ATib ( *R ) == NULL ) )) {
         Children_visited2  =  Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) ;
         }
       else
         {
         if( ( ( Fg_ATib ( *R ) == NULL ) && ( Fd_ATib ( *R ) != NULL ) )) {
           Children_visited2  =  Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) ;
           }
         else
           {
           Children_visited2  =  ( ( Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) ) && ( Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) ) ) ;
          
         }
       }
     }
     return Children_visited2 ;
    }
  /*--------------------------------------------------------------------*/
  void Trav_leaf_gauche (Pointeur_ATib *R , Pointeur_Li *Trav2 , Pointeur_Li *Tail)
    {
      /** Variables locales **/
      Pointeur_Li Maillon=NULL;
      bool Ignore;
      bool Temp1;
      bool Temp2;
      Typestr_Tib S;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     if( *R != NULL) {
       Ignore  =  False ;
       if( Fg_ATib ( *R ) == NULL) {
         Temp1  =  True ;
         }
       else
         {
         Temp1  =  Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) ;
        
       } ;
       if( Fd_ATib ( *R ) == NULL) {
         Temp2  =  True ;
         }
       else
         {
         Temp2  =  Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) ;
        
       } ;
       _Px1 =  Fg_ATib ( *R ) ;
       Trav_leaf_gauche ( &_Px1, & *Trav2 , & *Tail ) ;
       _Px2 =  Fd_ATib ( *R ) ;
       Trav_leaf_gauche ( &_Px2, & *Trav2 , & *Tail ) ;
       if( Fg_ATib ( *R ) != NULL) {
         if( Temp1 != Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  )) {
           Ignore  =  True ;
           }
         else
           {
           if( Fd_ATib ( *R ) != NULL) {
             if( Temp2 != Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  )) {
               Ignore  =  True ;
               }
             else
               {
               Ignore  =  False ;
              
             } }
           else
             {
             Ignore  =  False ;
            
           }
         } }
       else
         {
         if( Fd_ATib ( *R ) != NULL) {
           if( Temp2 != Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  )) {
             Ignore  =  True ;
             }
           else
             {
             Ignore  =  False ;
            
           } }
         else
           {
           Ignore  =  False ;
          
         }
       } ;
       Temp1  =  ( ( Feuille ( & *R ) == True ) && ( Struct2_Tib ( Info_ATib ( *R )  ) == False ) ) ;
       Temp2  =  ( ( Struct2_Tib ( Info_ATib ( *R )  ) == False ) && ( Children_visited ( & *R ) == True ) ) ;
       if( ( ( Ignore == False ) && ( ( Temp1 == True ) || ( Temp2 == True ) ) ))   {
      /* Affectation globale de structure */
         S->Champ1 =   Info_ATib ( *R )->Champ1;
         S->Champ2 =   Info_ATib ( *R )->Champ2;
 ;
         Aff_struct2_Tib ( S  , True ) ;
         Aff_info_ATib ( *R , S ) ;
         Allouer_Li (& Maillon ) ;
         Aff_val_Li ( Maillon , Struct1_Tib ( S  ) ) ;
         Aff_adr_Li ( Maillon , NULL ) ;
         if( *Trav2 == NULL) {
           *Trav2  =  Maillon ;
           *Tail  =  *Trav2 ;
           }
         else
           {
           Aff_adr_Li ( *Tail , Maillon ) ;
           *Tail  =  Maillon ;
          
         }
       }
     }
    }
  /*--------------------------------------------------------------------*/
  Pointeur_Li Leaf_gauche (Pointeur_ATib *R) 
    {
      /** Variables locales **/
      Pointeur_Li Leaf_gauche2 =NULL;
      Pointeur_Li Trav2=NULL;
      Pointeur_Li Tail=NULL;

      /** Corps du module **/
     Trav2  =  NULL ;
     Tail  =  NULL ;
     while( Struct2_Tib ( Info_ATib ( *R )  ) != True) {
       Trav_leaf_gauche ( & *R , & Trav2 , & Tail ) ;
      
     } ;
     Leaf_gauche2  =  Trav2 ;
    
     return Leaf_gauche2 ;
    }
  /*--------------------------------------------------------------------*/
  void Trav_leaf_droite (Pointeur_ATib *R , Pointeur_Li *Trav4 , Pointeur_Li *Tail)
    {
      /** Variables locales **/
      Pointeur_Li Maillon=NULL;
      bool Ignore;
      bool Temp1;
      bool Temp2;
      Typestr_Tib S;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Type_Tib));
     if( *R != NULL) {
       Ignore  =  False ;
       if( Fg_ATib ( *R ) == NULL) {
         Temp1  =  True ;
         }
       else
         {
         Temp1  =  Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  ) ;
        
       } ;
       if( Fd_ATib ( *R ) == NULL) {
         Temp2  =  True ;
         }
       else
         {
         Temp2  =  Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  ) ;
        
       } ;
       _Px1 =  Fd_ATib ( *R ) ;
       Trav_leaf_droite ( &_Px1, & *Trav4 , & *Tail ) ;
       _Px2 =  Fg_ATib ( *R ) ;
       Trav_leaf_droite ( &_Px2, & *Trav4 , & *Tail ) ;
       if( Fg_ATib ( *R ) != NULL) {
         if( Temp1 != Struct2_Tib ( Info_ATib ( Fg_ATib ( *R ) )  )) {
           Ignore  =  True ;
           }
         else
           {
           if( Fd_ATib ( *R ) != NULL) {
             if( Temp2 != Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  )) {
               Ignore  =  True ;
               }
             else
               {
               Ignore  =  False ;
              
             } }
           else
             {
             Ignore  =  False ;
            
           }
         } }
       else
         {
         if( Fd_ATib ( *R ) != NULL) {
           if( Temp2 != Struct2_Tib ( Info_ATib ( Fd_ATib ( *R ) )  )) {
             Ignore  =  True ;
             }
           else
             {
             Ignore  =  False ;
            
           } }
         else
           {
           Ignore  =  False ;
          
         }
       } ;
       Temp1  =  ( ( Feuille ( & *R ) == True ) && ( Struct2_Tib ( Info_ATib ( *R )  ) == False ) ) ;
       Temp2  =  ( ( Struct2_Tib ( Info_ATib ( *R )  ) == False ) && ( Children_visited ( & *R ) == True ) ) ;
       if( ( ( Ignore == False ) && ( ( Temp1 == True ) || ( Temp2 == True ) ) ))   {
      /* Affectation globale de structure */
         S->Champ1 =   Info_ATib ( *R )->Champ1;
         S->Champ2 =   Info_ATib ( *R )->Champ2;
 ;
         Aff_struct2_Tib ( S  , True ) ;
         Aff_info_ATib ( *R , S ) ;
         Allouer_Li (& Maillon ) ;
         Aff_val_Li ( Maillon , Struct1_Tib ( S  ) ) ;
         Aff_adr_Li ( Maillon , NULL ) ;
         if( *Trav4 == NULL) {
           *Trav4  =  Maillon ;
           *Tail  =  *Trav4 ;
           }
         else
           {
           Aff_adr_Li ( *Tail , Maillon ) ;
           *Tail  =  Maillon ;
          
         }
       }
     }
    }
  /*--------------------------------------------------------------------*/
  Pointeur_Li Leaf_droite (Pointeur_ATib *R) 
    {
      /** Variables locales **/
      Pointeur_Li Leaf_droite2 =NULL;
      Pointeur_Li Trav4=NULL;
      Pointeur_Li Tail=NULL;

      /** Corps du module **/
     Trav4  =  NULL ;
     Tail  =  NULL ;
     while( Struct2_Tib ( Info_ATib ( *R )  ) != True) {
       Trav_leaf_droite ( & *R , & Trav4 , & Tail ) ;
      
     } ;
     Leaf_droite2  =  Trav4 ;
    
     return Leaf_droite2 ;
    }
  /*---------------------------------------------------------------------*/
  bool  Comparer_listes (Pointeur_Li *Temp1 , Pointeur_Li *Temp2) 
    {
      /** Variables locales **/
      bool  Comparer_listes2 ;
      Pointeur_Li L1=NULL;
      Pointeur_Li L2=NULL;
      bool Error;

      /** Corps du module **/
     Error  =  False ;
     L1  =  *Temp1 ;
     L2  =  *Temp2 ;
     while( ( ( L1 != NULL ) && ( L2 != NULL ) && ( Error == False ) ))  {
       if( Valeur_Li ( L1 ) != Valeur_Li ( L2 )) {
         Error  =  True ;
        
       } ;
       L1  =  Suivant_Li ( L1 ) ;
       L2  =  Suivant_Li ( L2 ) ;
      
     } ;
     if( ( ( L1 != NULL ) || ( L2 != NULL ) || ( Error == True ) ))   {
       Comparer_listes2  =  False ;
       }
     else
       {
       Comparer_listes2  =  True ;
      
     }
     return Comparer_listes2 ;
    }
  /*----------------------------------------------------------------------*/
  Pointeur_ATib Verif_leaf_trav_g (Pointeur_ATib *N , Pointeur_Li *Verif2 , Pointeur_Li *Tail) 
    {
      /** Variables locales **/
      Pointeur_ATib Verif_leaf_trav_g2 =NULL;
      Pointeur_ATib Adrg=NULL;
      Pointeur_ATib Adrd=NULL;
      Pointeur_Li Maillon=NULL;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *N != NULL) {
       if( Feuille ( & *N )) {
         Allouer_Li (& Maillon ) ;
         Aff_val_Li ( Maillon , Struct1_Tib ( Info_ATib ( *N )  ) ) ;
         Aff_adr_Li ( Maillon , NULL ) ;
         if( *Verif2 == NULL) {
           *Verif2  =  Maillon ;
           *Tail  =  *Verif2 ;
           }
         else
           {
           Aff_adr_Li ( *Tail , Maillon ) ;
           *Tail  =  Maillon ;
          
         } ;
         Liberernoeud_ATib ( *N ) ;
         *N  =  NULL ;
         }
       else
         {
         _Px1 =  Fg_ATib ( *N ) ;
         Adrg  =  Verif_leaf_trav_g ( &_Px1, & *Verif2 , & *Tail ) ;
         Aff_fg_ATib ( *N , Adrg ) ;
         _Px2 =  Fd_ATib ( *N ) ;
         Adrd  =  Verif_leaf_trav_g ( &_Px2, & *Verif2 , & *Tail ) ;
         Aff_fd_ATib ( *N , Adrd ) ;
        
       }
     } ;
     Verif_leaf_trav_g2  =  *N ;
    
     return Verif_leaf_trav_g2 ;
    }
  /*----------------------------------------------------------------------*/
  Pointeur_Li Verif_leaf_g (Pointeur_ATib *N) 
    {
      /** Variables locales **/
      Pointeur_Li Verif_leaf_g2 =NULL;
      Pointeur_Li Verif2=NULL;
      Pointeur_Li Tail=NULL;

      /** Corps du module **/
     Verif2  =  NULL ;
     Tail  =  NULL ;
     while( *N != NULL) {
       *N  =  Verif_leaf_trav_g ( & *N , & Verif2 , & Tail ) ;
      
     } ;
     Verif_leaf_g2  =  Verif2 ;
    
     return Verif_leaf_g2 ;
    }
  /*----------------------------------------------------------------------*/
  Pointeur_ATib Verif_leaf_trav_d (Pointeur_ATib *N , Pointeur_Li *Verif2 , Pointeur_Li *Tail) 
    {
      /** Variables locales **/
      Pointeur_ATib Verif_leaf_trav_d2 =NULL;
      Pointeur_ATib Adrg=NULL;
      Pointeur_ATib Adrd=NULL;
      Pointeur_Li Maillon=NULL;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *N != NULL) {
       if( Feuille ( & *N )) {
         Allouer_Li (& Maillon ) ;
         Aff_val_Li ( Maillon , Struct1_Tib ( Info_ATib ( *N )  ) ) ;
         Aff_adr_Li ( Maillon , NULL ) ;
         if( *Verif2 == NULL) {
           *Verif2  =  Maillon ;
           *Tail  =  *Verif2 ;
           }
         else
           {
           Aff_adr_Li ( *Tail , Maillon ) ;
           *Tail  =  Maillon ;
          
         } ;
         Liberernoeud_ATib ( *N ) ;
         *N  =  NULL ;
         }
       else
         {
         _Px1 =  Fd_ATib ( *N ) ;
         Adrd  =  Verif_leaf_trav_d ( &_Px1, & *Verif2 , & *Tail ) ;
         Aff_fd_ATib ( *N , Adrd ) ;
         _Px2 =  Fg_ATib ( *N ) ;
         Adrg  =  Verif_leaf_trav_d ( &_Px2, & *Verif2 , & *Tail ) ;
         Aff_fg_ATib ( *N , Adrg ) ;
        
       }
     } ;
     Verif_leaf_trav_d2  =  *N ;
    
     return Verif_leaf_trav_d2 ;
    }
  /*----------------------------------------------------------------------*/
  Pointeur_Li Verif_leaf_d (Pointeur_ATib *N) 
    {
      /** Variables locales **/
      Pointeur_Li Verif_leaf_d2 =NULL;
      Pointeur_Li Verif2=NULL;
      Pointeur_Li Tail=NULL;

      /** Corps du module **/
     Verif2  =  NULL ;
     Tail  =  NULL ;
     while( *N != NULL) {
       *N  =  Verif_leaf_trav_d ( & *N , & Verif2 , & Tail ) ;
      
     } ;
     Verif_leaf_d2  =  Verif2 ;
    
     return Verif_leaf_d2 ;
    }
  /*-----------------------------------------------------------------------*/
  void Liste_preordre_g (Pointeur_ATib *N , Pointeur_LATib *Head , Pointeur_LATib *Tail)
    {
      /** Variables locales **/
      Pointeur_LATib Maillon=NULL;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *N != NULL) {
       Allouer_LATib (& Maillon ) ;
       Aff_val_LATib ( Maillon , *N ) ;
       Aff_adr_LATib ( Maillon , NULL ) ;
       if( *Head == NULL) {
         *Head  =  Maillon ;
         *Tail  =  *Head ;
         }
       else
         {
         Aff_adr_LATib ( *Tail , Maillon ) ;
         *Tail  =  Maillon ;
        
       } ;
       _Px1 =  Fg_ATib ( *N ) ;
       Liste_preordre_g ( &_Px1, & *Head , & *Tail ) ;
       _Px2 =  Fd_ATib ( *N ) ;
       Liste_preordre_g ( &_Px2, & *Head , & *Tail ) ;
      
     }
    }
  /*-----------------------------------------------------------------------*/
  Pointeur_Li Branche_gauche (Pointeur_ATib *N) 
    {
      /** Variables locales **/
      Pointeur_Li Branche_gauche2 =NULL;
      Pointeur_ATib Temp=NULL;
      Pointeur_ATib Temp2=NULL;
      Pointeur_LATib T=NULL;
      Pointeur_LATib T2=NULL;
      Pointeur_PATib P=NULL;
      Pointeur_Li Trav1=NULL;
      Pointeur_Li Tail=NULL;
      Pointeur_Li Maillon=NULL;

      /** Corps du module **/
     T  =  NULL ;
     Trav1  =  NULL ;
     T2  =  NULL ;
     Liste_preordre_g ( & *N , & T , & T2 ) ;
     while( T != NULL) {
       Temp2  =  Valeur_LATib ( T ) ;
       while( ! Feuille ( & Temp2 )) {
         Empiler_PATib (& P , Valeur_LATib ( T ) ) ;
         T  =  Suivant_LATib ( T ) ;
         Temp2  =  Valeur_LATib ( T ) ;

        
       } ;
       Empiler_PATib (& P , Valeur_LATib ( T ) ) ;
       while( ! Pilevide_PATib ( P )) {
         Depiler_PATib (& P , &Temp ) ;
         Allouer_Li (& Maillon ) ;
         Aff_val_Li ( Maillon , Struct1_Tib ( Info_ATib ( Temp )  ) ) ;
         Aff_adr_Li ( Maillon , NULL ) ;
         if( Trav1 == NULL) {
           Trav1  =  Maillon ;
           Tail  =  Trav1 ;
           }
         else
           {
           Aff_adr_Li ( Tail , Maillon ) ;
           Tail  =  Maillon ;
          
         } ;
        
       } ;
       T  =  Suivant_LATib ( T ) ;
      
     } ;
     Branche_gauche2  =  Trav1 ;
    
     return Branche_gauche2 ;
    }
  /*-----------------------------------------------------------------------*/
  void Liste_preordre_d (Pointeur_ATib *N , Pointeur_LATib *Head , Pointeur_LATib *Tail)
    {
      /** Variables locales **/
      Pointeur_LATib Maillon=NULL;
      Pointeur_ATib _Px1=NULL;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     if( *N != NULL) {
       Allouer_LATib (& Maillon ) ;
       Aff_val_LATib ( Maillon , *N ) ;
       Aff_adr_LATib ( Maillon , NULL ) ;
       if( *Head == NULL) {
         *Head  =  Maillon ;
         *Tail  =  *Head ;
         }
       else
         {
         Aff_adr_LATib ( *Tail , Maillon ) ;
         *Tail  =  Maillon ;
        
       } ;
       _Px1 =  Fd_ATib ( *N ) ;
       Liste_preordre_d ( &_Px1, & *Head , & *Tail ) ;
       _Px2 =  Fg_ATib ( *N ) ;
       Liste_preordre_d ( &_Px2, & *Head , & *Tail ) ;
      
     }
    }
  /*-----------------------------------------------------------------------*/
  Pointeur_Li Branche_droite (Pointeur_ATib *N) 
    {
      /** Variables locales **/
      Pointeur_Li Branche_droite2 =NULL;
      Pointeur_ATib Temp=NULL;
      Pointeur_ATib Temp2=NULL;
      Pointeur_LATib T=NULL;
      Pointeur_LATib T2=NULL;
      Pointeur_PATib P=NULL;
      Pointeur_Li Trav1=NULL;
      Pointeur_Li Tail=NULL;
      Pointeur_Li Maillon=NULL;

      /** Corps du module **/
     T  =  NULL ;
     Trav1  =  NULL ;
     T2  =  NULL ;
     Liste_preordre_d ( & *N , & T , & T2 ) ;
     while( T != NULL) {
       Temp2  =  Valeur_LATib ( T ) ;
       while( ! Feuille ( & Temp2 )) {
         Empiler_PATib (& P , Valeur_LATib ( T ) ) ;
         T  =  Suivant_LATib ( T ) ;
         Temp2  =  Valeur_LATib ( T ) ;
        
       } ;
       Empiler_PATib (& P , Valeur_LATib ( T ) ) ;
       while( ! Pilevide_PATib ( P )) {
         Depiler_PATib (& P , &Temp ) ;
         Allouer_Li (& Maillon ) ;
         Aff_val_Li ( Maillon , Struct1_Tib ( Info_ATib ( Temp )  ) ) ;
         Aff_adr_Li ( Maillon , NULL ) ;
         if( Trav1 == NULL) {
           Trav1  =  Maillon ;
           Tail  =  Trav1 ;
           }
         else
           {
           Aff_adr_Li ( Tail , Maillon ) ;
           Tail  =  Maillon ;
          
         } ;
        
       } ;
       T  =  Suivant_LATib ( T ) ;
      
     } ;
     Branche_droite2  =  Trav1 ;
    
     return Branche_droite2 ;
    }
  /*----------------------------------------------------------------------------*/
  void Affiche_tout (Pointeur_ATib *R , Pointeur_ATib *R_copy)
    {
      /** Variables locales **/
      Pointeur_ATib Temp=NULL;

      /** Corps du module **/
     printf ( " %s", "" ) ;
     printf ( " %s", "le parcour inordre : " ) ;
     printf ( " %s", "" ) ;
     Temp  =  *R ;
     Inordre ( & Temp ) ;
     printf ( " %s", "est ce que l arbre est bien construit : " ) ;
     printf ( " %d", Verifier_arb(&*R) ) ;
     printf ( " %s", "" ) ;
     Trav1  =  Branche_gauche ( & *R ) ;
     Verif1  =  Verif_branche_g ( & *R ) ;
     Clear_visited ( & *R ) ;
     Trav2  =  Leaf_gauche ( & *R ) ;
     Verif2  =  Verif_leaf_g ( & *R ) ;
     printf ( " %s", "traverse 1 : branche par branche du gauche a droite" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Trav1 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "verification 1 : branche par branche du gauche a droite" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Verif1 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav1,&Verif1) ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "traverse 2 : feuille par feuille du gauche a droite" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Trav2 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "verification 2 : feuille par feuille du gauche a droite" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Verif2 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav2,&Verif2) ) ;
     printf ( " %s", "" ) ;
     Trav3  =  Branche_droite ( & *R_copy ) ;
     Verif3  =  Verif_branche_d ( & *R_copy ) ;
     Clear_visited ( & *R_copy ) ;
     Trav4  =  Leaf_droite ( & *R_copy ) ;
     Verif4  =  Verif_leaf_d ( & *R_copy ) ;
     printf ( " %s", "traverse 3 : branche par branche du droite a gauche" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Trav3 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "verification 3 : branche par branche du droite a gauche" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Verif3 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav3,&Verif3) ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "traverse 4  : feuille par feuille du droite a gauche" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Trav4 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "verification 4 : feuille par feuille du droite a gauche" ) ;
     printf ( " %s", "" ) ;
     Print_liste ( & Verif4 ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav4,&Verif4) ) ;
     printf ( " %s", "" ) ;
    
    }
  /*------------------------------------------------------------------------------------*/
  void Affiche_resume (Pointeur_ATib *R , Pointeur_ATib *R_copy)
    {

      /** Corps du module **/
     printf ( " %s", "est ce que l arbre est bien construit : " ) ;
     printf ( " %d", Verifier_arb(&*R) ) ;
     printf ( " %s", "" ) ;
     Trav1  =  Branche_gauche ( & *R ) ;
     Verif1  =  Verif_branche_g ( & *R ) ;
     Clear_visited ( & *R ) ;
     Trav2  =  Leaf_gauche ( & *R ) ;
     Verif2  =  Verif_leaf_g ( & *R ) ;
     printf ( " %s", "traverse 1 : branche par branche du gauche a droite" ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav1,&Verif1) ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "traverse 2 : feuille par feuille du gauche a droite" ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav2,&Verif2) ) ;
     printf ( " %s", "" ) ;
     Trav3  =  Branche_droite ( & *R_copy ) ;
     Verif3  =  Verif_branche_d ( & *R_copy ) ;
     Clear_visited ( & *R_copy ) ;
     Trav4  =  Leaf_droite ( & *R_copy ) ;
     Verif4  =  Verif_leaf_d ( & *R_copy ) ;
     printf ( " %s", "traverse 3 : branche par branche du droite a gauche" ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav3,&Verif3) ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "traverse 2 : feuille par feuille du droite a gauche" ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "comparaison des deux listes : " ) ;
     printf ( " %s", "" ) ;
     printf ( " %d", Comparer_listes(&Trav4,&Verif4) ) ;
     printf ( " %s", "" ) ;
    
    }

void home_page()
{ // displays ESI logo

    system("cls"); // clear the terminal
    printf("\t\t\t\t\033[96m           Democratic Republic Of Algeria           \033[0m\n");
    printf("\t\t\t\t\033[96mMinistry Of Higher Education And Scientific Research\033[0m\n");
    printf("\t\t\t      \033[96m _______________________________________________________\n");
    printf("\t\t\t      \033[96m|        \033[92m_______\033[0m    \033[91m _______\033[0m    \033[97m _\033[0m                      \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|  _____|\033[0m   \033[97m| |\033[0m  \033[92m%ccole nationale\033[0m    \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m| |_____\033[0m    \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|  _____|\033[0m   \033[91m|_____  |\033[0m   \033[97m| |\033[0m  \033[91msup%crieure\033[0m         \033[96m|\n", 130);
    printf("\t\t\t      \033[96m|       \033[92m| |_____\033[0m    \033[91m _____| |\033[0m   \033[97m| |\033[0m                     \033[96m|\n");
    printf("\t\t\t      \033[96m|       \033[92m|_______|\033[0m   \033[91m|_______|\033[0m   \033[97m|_|\033[0m  \033[97md'informatique\033[0m     \033[96m|\n");
    printf("\t\t\t      \033[96m|_______________________________________________________|\033[0m\n\n");

    printf("\t\t\t\t\t\033[96m            1CP - 2023/2024 \n", 138, 130, 130);
    printf("\t\t\t\033[96m ___________________________________________________________________\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|           REALISED BY :  \033[97m     Hadim Anes Abdelhak\033[96m                 |\n");
    printf("\t\t\t\033[96m|                                        &                          |\n");
    printf("\t\t\t\033[96m|                           \033[97m      Zeghmar Abdellah\033[96m                  |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|           SECTION :  \033[97mA\033[96m          GROUPE: \033[97m03\033[96m                        |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|           TP2 :  \033[97mmultiple methodes de parcours des arbres\033[96m         |\n");
    printf("\t\t\t\033[96m|                                                                   |\n");
    printf("\t\t\t\033[96m|___________________________________________________________________|\n\n\n");

    printf("\t\t\t                              \033[91mPlease                                \n");
    printf("\t\t\t                   Enter Any Button To Continue...\033[0m               ");
    getch();

    system("cls");
}

//-----------------------------------------------//-----------------------------------------------//

void loading_page()
{ // displays a simple loading animation

    // just displaying a diffrent frame after each 300ms
    // and clear the terminal after each frame

    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("\t\t\t\t\t\t|||                                                 5%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t|||||                                               20%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t||||||||||||||||                                    30%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t|||||||||||||||||||||||||                           45%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t|||||||||||||||||||||||||||||||                     60%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||            80%%  ");
    Sleep(300);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||  100%% ");
    system("cls");
}

//-----------------------------------------------//-----------------------------------------------//

void hold_results()
{ // to let the user see the results before clearing the terminal
    printf("\npress Enter to continue");
    getch();
    system("Clr");
}

void print_tree(Pointeur_ATib root, int space,int val)
{
  if (root == NULL)
  {
    return;
  }

  space += 10;
  print_tree(Fd_ATib(root), space,val);

  printf("\n");
  for (int i = 10; i < space; i++)
  {
    printf(" ");
  }
  if (Struct1_Tib(Info_ATib(root))==val) {
    S=Info_ATib(root);
    Aff_struct2_Tib(S,1);
    Aff_info_ATib(root,S);
  }
  
  if (Struct2_Tib(Info_ATib(root))==1 && Struct1_Tib(Info_ATib(root))!=val) {
    printf("\033[31m%d\n\033[0m",  Struct1_Tib(Info_ATib(root)));
  } else if (Struct2_Tib(Info_ATib(root))==1 && Struct1_Tib(Info_ATib(root))==val) {
    printf("\033[31m==>%d\n\033[0m",  Struct1_Tib(Info_ATib(root)));
  } else {
    printf("%d\n",  Struct1_Tib(Info_ATib(root)));
  }
  print_tree(Fg_ATib(root), space,val);
}

void print_animated_tree(Pointeur_ATib root,Pointeur_Li T ){
  while(T!=NULL){
    print_tree(root,0,Valeur_Li(T));
    Sleep(1000);
    T=Suivant_Li(T);
    system("cls");
  }
}

// sub-menus logic same as the main-menu to get the arrow animation

void sub_menu_1(Pointeur_ATib R)
{

    int choice = 1;
    int max_choice = 5;
    char c;

    int array_size; 
    int size;       

    do
    {

        do
        {

            system("cls");

            printf("########################################################################################################################\n");
            printf("#%118c#\n", 32);
            printf("#%30cLes differents methode de parcoure %53c\033[0m#\n", 32, 32);
            printf("#%118c#\n", 32);
            printf("########################################################################################################################\n");
            printf("#%118c#\n", 32);
            printf("#%47cchoose an option:%54c#\n", 32, 32);
            printf("#%118c#\n", 32);
            int i;
            for (i = 1; i <= max_choice; i++)
            {
                if (i == choice)
                {
                    printf("#\033[34m --> ");
                }
                else
                {
                    printf("#     ");
                }
                switch (i)
                {
                case 1:
                    printf("1) Parcours branche par branche du gauche vers la droite%57c\033[0m#\n", 32);
                    break;
                case 2:
                    printf("2) Parcours feuille par feuille du gauche vers la droite%57c\033[0m#\n", 32);
                    break;
                case 3:
                    printf("3) Parcours branche par branche du droite vers la gauche%57c\033[0m#\n", 32);
                    break;
                case 4:
                    printf("4) Parcours feuille par feuille du droite vers la gauche%57c\033[0m#\n", 32);
                    break;
                case 5:
                    printf("5) retourner vers le menu principale%77c\033[0m#\n", 32);
                    break;

                }
            }

            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("########################################################################################################################\n");
            printf("#%118c#\n", 32);
            printf("#%36c\033[31mHow to navigate throught the menu\033[0m%49c#\n", 32, 32);
            printf("#%26c\033[31mUse the Up and Down arrows or the numbers from 1 to %d\033[0m%39c#\n", 32, max_choice, 32);
            printf("#%26c\033[31mPress enter to choose the option after selecting it\033[0m%41c#\n", 32, 32);
            printf("#%118c#\n", 32);
            printf("########################################################################################################################\n");

        Read1:
            c = getch();

            switch (c)
            {
            case 72:
                if (choice > 1)
                {
                    choice--;
                }
                else if (choice == 1)
                {
                    choice = max_choice;
                }
                break;
            case 80:
                if (choice < max_choice)
                {
                    choice++;
                }
                else if (choice == max_choice)
                {
                    choice = 1;
                }
                break;
            case 49:
                choice = 1;
                break;
            case 50:
                choice = 2;
                break;
            case 51:
                choice = 3;
                break;
            case 52:
                choice=4;
                break;
            case 53:
                choice = 5;
                break;
            case 13:
                c = 13;
                break;
            default:
                goto Read1;
                break;
            }
        } while (c != 13);

        system("cls");

        switch (choice)
        {
        case 1:
            Trav1 = Branche_gauche(&R);
            print_animated_tree(R,Trav1);
            Clear_visited(&R);
            printf("\n");
            Print_liste(&Trav1);
            hold_results();
            break;
        case 2: 
            Trav2 = Leaf_gauche(&R);
            Clear_visited(&R);
            print_animated_tree(R,Trav2);
            Clear_visited(&R);
            printf("\n");
            Print_liste(&Trav2);
            hold_results();
            break;
        case 3:
            Trav3 = Branche_droite(&R);
            print_animated_tree(R,Trav3);
            Clear_visited(&R);
            printf("\n");
            Print_liste(&Trav3);
            hold_results();
            break;
        case 4: 
            Trav4 = Leaf_droite(&R);
            Clear_visited(&R);
            print_animated_tree(R,Trav4);
            Clear_visited(&R);
            printf("\n");
            Print_liste(&Trav4);
            hold_results();
            break;
        case 5:
            printf("exite");
        }
    } while (choice != 5);

}

void main_menu()
{ // the menu where the user manipulates the differente questions in the TP
    int val;
    int choice = 1; // the option choosed (set default to one)
    int max_choice = 2; // the total number of options
    char c;             // the keyboard key pressed by the user
                        // loop until the user press ESC
    do
    {
        // loop until the user press Enter
        do
        {
            // display the menu each time the user updates his choice
            system("cls");

            printf("########################################################################################################################\n");
            printf("#%118c#\n", 32);
            printf("#%52cMAIN MENU%57c#\n", 32, 32);
            printf("#%118c#\n", 32);
            printf("########################################################################################################################\n");
            printf("#%118c#\n", 32);
            printf("#%49cChoose an option:%52c#\n", 32, 32);
            printf("#%118c#\n", 32);
            // the arrow will be before the choosed option
            int i;
            for (i = 1; i <= max_choice; i++)
            {
                if (i == choice)
                {
                        printf("#\033[34m --> ");
                }
                else
                {
                    printf("\033[0m#     ");
                }
                switch (i)
                {

                case 1:
                    printf("1) Tester les parcours sur L'arbre du TP%73c\033[0m#\n", 32);
                    break;
                case 2:
                    printf("2) Tester les parcours par une arbre de votre choix%62c\033[0m#\n", 32);
                    break;
                }
            }

            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("#%118c#\n", 32);
            printf("########################################################################################################################\n");
            printf("#%118c#\n", 32);
            printf("#%36c\033[31mHow to navigate throught the menu\033[0m%49c#\n", 32, 32);
            printf("#%26c\033[31mUse the Up and Down arrows or the numbers from 1 to %d\033[0m%39c#\n", 32, max_choice, 32);
            printf("#%26c\033[31mPress enter to choose the option after selecting it\033[0m%41c#\n", 32, 32);
            printf("#%36c\033[31mTo quite the program press 'Esc'\033[0m%50c#\n", 32, 32);
            printf("#%118c#\n", 32);
            printf("########################################################################################################################\n");

            // get the keyboard key pressed by the user
        Read:
            c = getch();

            // change the arrow position or quite the program based on the c value (the key pressed)
            switch (c)
            {
            case 72: // Arrow Up
                if (choice > 1)
                {
                    choice--; // go up
                }
                else if (choice == 1)
                {
                    choice = max_choice; // or go to the last option (circularly)
                }
                break;
            case 80: // Arrow Down
                if (choice < max_choice)
                {
                    choice++; // go down
                }
                else if (choice == max_choice)
                {
                    choice = 1; // or go to the first option (circularly)
                }
                break;
            case 49: // for the number '1'
                choice = 1;
                break;
            case 50: // '2'
                choice = 2;
                break;
            case 13: // confirm the choice with Enter
                c = 13;
                break;
            case 27: // quite the program after pressing ESC
                choice = max_choice+1;
                c = 13;
                break;
            default:
                goto Read; // Ignorer les autres touches et relire le choice
                break;
            }
        } while (c != 13); // repeat this loop until the key pressed is ESC
        // execute the user's choice
        system("Cls");                              
        int size;             

        switch (choice)
        {
        case 1: // arbre du TP
            val=45;
            R=Insertion(& R,&val,&Inserer);
            val=20;
            R=Insertion(& R,&val,&Inserer);
            val=10;
            R=Insertion(& R,&val,&Inserer);
            val=35;
            R=Insertion(& R,&val,&Inserer);
            val=65;
            R=Insertion(& R,&val,&Inserer);
            val=55;
            R=Insertion(& R,&val,&Inserer);
            val=50;
            R=Insertion(& R,&val,&Inserer);
            val=58;
            R=Insertion(& R,&val,&Inserer);
            val=56;
            R=Insertion(& R,&val,&Inserer);
            val=57;
            R=Insertion(& R,&val,&Inserer);
            val=60;
            R=Insertion(& R,&val,&Inserer);
            val=62;
            R=Insertion(& R,&val,&Inserer);
            val=85;
            R=Insertion(& R,&val,&Inserer);
            val=75;
            R=Insertion(& R,&val,&Inserer);
            val=95;
            R=Insertion(& R,&val,&Inserer);
            val=90;
            R=Insertion(& R,&val,&Inserer);
            val=88;
            R=Insertion(& R,&val,&Inserer);
            val=98;
            R=Insertion(& R,&val,&Inserer);
            sub_menu_1(R);
            break;
        case 2: // arbre par votre choix
            printf("entre le nombre de elements dans votre arbre : ");
            scanf("%d",&size);
            for(int i=0;i<size;i++){
              printf("entre une valeur : ") ;
              scanf("%d",&val);
              R=Insertion(&R,&val,&Inserer);
            }
            sub_menu_1(R);
            break;
        }
    } while (choice != max_choice+1);

    // End of Program
    system("cls");
    printf("\n\n        thank you for using our program\n\n");
    printf("        Press enter to quite the program . . .");
    getch();
}



int main()
  {
    home_page();
    loading_page();
    main_menu();
    return 0;
  }