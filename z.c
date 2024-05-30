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
      Pointeur_Li Head=NULL;
      Pointeur_Li Next=NULL;
      bool Error;
      typedef * Pointeur_nil ;   // Pointeur generique
      Pointeur_nil _Px1;

      /** Corps du module **/
     Head  =  NULL ;
     _Px1 =  NULL ;
     List_inordre ( & *Noeud , & Head , &_Px1) ;
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
      Pointeur_LATib T=NULL;
      Pointeur_PATib P=NULL;
      Pointeur_Li Trav1=NULL;
      Pointeur_Li Tail=NULL;
      Pointeur_Li Maillon=NULL;
      typedef * Pointeur_nil ;   // Pointeur generique
      Pointeur_nil _Px1;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     T  =  NULL ;
     Trav1  =  NULL ;
     _Px1 =  NULL ;
     Liste_preordre_g ( & *N , & T , &_Px1) ;
     while( T != NULL) {
       _Px2 =  Valeur_LATib ( T ) ;
       while( ! Feuille ( &_Px2)) {
         Empiler_PATib (& P , Valeur_LATib ( T ) ) ;
         T  =  Suivant_LATib ( T ) ;
        
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
      Pointeur_LATib T=NULL;
      Pointeur_PATib P=NULL;
      Pointeur_Li Trav1=NULL;
      Pointeur_Li Tail=NULL;
      Pointeur_Li Maillon=NULL;
      typedef * Pointeur_nil ;   // Pointeur generique
      Pointeur_nil _Px1;
      Pointeur_ATib _Px2=NULL;

      /** Corps du module **/
     T  =  NULL ;
     Trav1  =  NULL ;
     _Px1 =  NULL ;
     Liste_preordre_d ( & *N , & T , &_Px1) ;
     while( T != NULL) {
       _Px2 =  Valeur_LATib ( T ) ;
       while( ! Feuille ( &_Px2)) {
         Empiler_PATib (& P , Valeur_LATib ( T ) ) ;
         T  =  Suivant_LATib ( T ) ;
        
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

      /** Corps du module **/
     printf ( " %s", "" ) ;
     printf ( " %s", "le parcour inordre : " ) ;
     printf ( " %s", "" ) ;
     Inordre ( & *R ) ;
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

  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     printf ( " %s", "---------TP2--------" ) ;
     printf ( " %s", "-------------------------------------------------------" ) ;
     printf ( " %s", "test sur les 10 arbres avec 100 noeuds : " ) ;
     printf ( " %s", "on vas aficher en detaile seulement l arbre 1" ) ;
     M  =  10 ;
     N  =  100 ;
     I  =  1 ;
     for( I  =  1 ;I <=  M ; ++I) {
       R  =  NULL ;
       R_copy  =  NULL ;
       for( J  =  1 ;J <=  N ; ++J) {
         Inserer  =  False ;
         while( Inserer == False)  {
           Val  =  Aleanombre(1000 ) ;
           R  =  Insertion ( & R , & Val , & Inserer ) ;
          
         } ;
         R_copy  =  Insertion ( & R_copy , & Val , & Inserer ) ;
        
       } ;
       printf ( " %s", "-----------------------------------------------------" ) ;
       printf ( " %s", "-----------------arbre" );
       printf ( " %d", I );
       printf ( " %s", "-----------------------------" ) ;
       if( I == 1)   {
         Affiche_tout ( & R , & R_copy ) ;
         }
       else
         {
         Affiche_resume ( & R , & R_copy ) ;
        
       }
     } ;
    
   
      system("PAUSE");
      return 0;
    }