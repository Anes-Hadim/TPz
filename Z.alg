
   SOIT
  { 
       --------------------------------------------- 
      }
       R UN ARB DE ( ENTIER , BOOLEEN ) ;
       Inserer , Is_search : BOOLEEN ;
       Val , I , J , N , M : ENTIER ;
      { 
        -------------------------------------------- 
       }
       Trav1 , Trav2 , Trav3 , Trav4 : LISTE DE ENTIER ;
       Verif1 , Verif2 , Verif3 , Verif4 : LISTE DE ENTIER ;
      { 
        -------------------------------------------- 
       }
       Arbre_tp , Print_liste : ACTION ;
       Info1 , Info2 , Info_impair , Info_pair : ACTION ;
       Feuille , Children_visited , Verifier_arb , Comparer_listes : FONCTION ( BOOLEEN ) ;
       Insertion : FONCTION ( ARB DE ( ENTIER , BOOLEEN ) ) ;
       Inordre , List_inordre , Free_arb , Iter_stack , Clear_visited : ACTION ;
      { 
        -------------------------------------------- 
       }
       Liste_preordre_g , Liste_preordre_d : ACTION ;
       Branche_gauche , Branche_droite : FONCTION ( LISTE DE ENTIER ) ;
       Verif_branche_g , Verif_branche_d : FONCTION ( LISTE DE ENTIER ) ;
      { 
        -------------------------------------------- 
       }
       Trav_leaf_gauche , Trav_leaf_droite : ACTION ;
       Leaf_gauche , Leaf_droite : FONCTION ( LISTE DE ENTIER ) ;
       Verif_leaf_trav_g , Verif_leaf_trav_d : FONCTION ( ARB DE ( ENTIER , BOOLEEN ) ) ;
       Verif_leaf_g , Verif_leaf_d : FONCTION ( LISTE DE ENTIER ) ;
      
   DEBUT
       R := NIL ;
       ECRIRE ( '---------TP2--------' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'Test sur l exemple du TP' ) ;
       APPEL Arbre_tp ( R ) ;
       Trav1 := Branche_gauche ( R ) ;
       Verif1 := Verif_branche_g ( R ) ;
       APPEL Clear_visited ( R ) ;
       Trav3 := Branche_droite ( R ) ;
       Verif3 := Verif_branche_d ( R ) ;
       APPEL Clear_visited ( R ) ;
       Trav2 := Leaf_gauche ( R ) ;
       Verif2 := Verif_leaf_g ( R ) ;
       APPEL Arbre_tp ( R ) ;
       Trav4 := Leaf_droite ( R ) ;
       Verif4 := Verif_leaf_d ( R ) ;
       APPEL Free_arb ( R ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 1 : branche par branche du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav1 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 1 : branche par branche du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif1 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav1 , Verif1 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 3 : branche par branche du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav3 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 3 : branche par branche du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif3 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav3 , Verif3 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 2  : feuille par feuille du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav2 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 2 : feuille par feuille du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif2 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav2 , Verif2 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 4 : feuille par feuille du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav4 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 4 : feuille par feuille du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif4 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav4 , Verif4 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'test sur les 10 arbres avec 100 noeuds : ' ) ;
       ECRIRE ( 'on vas tester les traverser du gauche a droite sur 5 arbres' ) ;
       ECRIRE ( 'et du droite a gauche sur les autre 5 arbres' ) ;
       ECRIRE ( 'on vas aficher en detaile seulement les arbres 1 et 2' ) ;
       M := 10 ;
       N := 100 ;
       I := 1 ;
       POUR I := 1 , M :
           R := NIL ;
           POUR J := 1 , N :
               Inserer := FAUX ;
               TANTQUE Inserer = FAUX :
                   Val := ALEANOMBRE ( 1000 ) ;
                   R := Insertion ( R , Val , Inserer ) ;
                  
               FINTANTQUE
           FINPOUR ;
           ECRIRE ( '-----------------------------------------------------' ) ;
           ECRIRE ( '-----------------arbre' , I , '-----------------------------' ) ;
           SI MOD ( I , 2 ) = 1 :
               SI I = 1
                   APPEL Info1 ( R ) ;
                  
               SINON
                   APPEL Info_impair ( R ) ;
                  
               FINSI
           SINON
               SI I = 2
                   APPEL Info2 ( R ) ;
                  
               SINON
                   APPEL Info_pair ( R )
               FINSI ;
              
           FINSI ;
           APPEL Free_arb ( R ) ;
          
       FINPOUR ;
      
   FIN
  {--------------------------------------------------------------------}
   ACTION Arbre_tp ( R )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       R := Insertion ( R , 45 , Inserer ) ;
       R := Insertion ( R , 20 , Inserer ) ;
       R := Insertion ( R , 10 , Inserer ) ;
       R := Insertion ( R , 35 , Inserer ) ;
       R := Insertion ( R , 65 , Inserer ) ;
       R := Insertion ( R , 55 , Inserer ) ;
       R := Insertion ( R , 50 , Inserer ) ;
       R := Insertion ( R , 58 , Inserer ) ;
       R := Insertion ( R , 56 , Inserer ) ;
       R := Insertion ( R , 57 , Inserer ) ;
       R := Insertion ( R , 60 , Inserer ) ;
       R := Insertion ( R , 62 , Inserer ) ;
       R := Insertion ( R , 85 , Inserer ) ;
       R := Insertion ( R , 75 , Inserer ) ;
       R := Insertion ( R , 95 , Inserer ) ;
       R := Insertion ( R , 90 , Inserer ) ;
       R := Insertion ( R , 88 , Inserer ) ;
       R := Insertion ( R , 98 , Inserer ) ;
      
   FIN
  {--------------------------------------------------------------------}
   ACTION Print_liste ( Tete )
   SOIT
       Tete , Temp : LISTE DE ENTIER ;
      
   DEBUT
       Temp := Tete ;
       TANTQUE Temp <> NIL
           ECRIRE ( VALEUR ( Temp ) ) ;
           Temp := SUIVANT ( Temp ) ;
          
       FINTANTQUE
   FIN
  {--------------------------------------------------------------------}
   FONCTION Insertion ( Noed , Val , Ins ) : ARB DE ( ENTIER , BOOLEEN )
   SOIT
       Noed , N : ARB DE ( ENTIER , BOOLEEN ) ;
       Val : ENTIER ;
       Ins : BOOLEEN ;
       S : STRUCTURE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Noed = NIL
           INIT_STRUCT ( S , [ Val , FAUX ] ) ;
           CREERNOEUD ( N ) ;
           AFF_INFO ( N , S ) ;
           Ins := VRAI ;
           Noed := N ;
          
       SINON
           S := INFO ( Noed ) ;
           SI Val < STRUCT ( S , 1 )
               AFF_FG ( Noed , Insertion ( FG ( Noed ) , Val , Ins ) ) ;
              
           SINON
               SI Val > STRUCT ( S , 1 )
                   AFF_FD ( Noed , Insertion ( FD ( Noed ) , Val , Ins ) ) ;
                  
               SINON
                   Ins := FAUX ;
                  
               FINSI
           FINSI
       FINSI ;
       Insertion := Noed ;
      
   FIN
  {--------------------------------------------------------------------}
   FONCTION Feuille ( Noed ) : BOOLEEN
   SOIT
       Noed : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI ( ( FG ( Noed ) = NIL ) ET ( FD ( Noed ) = NIL ) ) :
           Feuille := VRAI ;
          
       SINON
           Feuille := FAUX ;
          
       FINSI
   FIN
  {--------------------------------------------------------------------}
   ACTION Inordre ( Noed )
   SOIT
       Noed : ARB DE ( ENTIER , BOOLEEN ) ;
       S : STRUCTURE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Noed <> NIL
           APPEL Inordre ( FG ( Noed ) ) ;
           S := INFO ( Noed ) ;
           ECRIRE ( STRUCT ( S , 1 ) ) ;
           APPEL Inordre ( FD ( Noed ) ) ;
          
       FINSI
   FIN
  {--------------------------------------------------------------------}
   ACTION Free_arb ( Noeud )
   SOIT
       Noeud : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Noeud <> NIL
           APPEL Free_arb ( FG ( Noeud ) ) ;
           APPEL Free_arb ( FD ( Noeud ) ) ;
           LIBERERNOEUD ( Noeud ) ;
          
       FINSI
   FIN
  {--------------------------------------------------------------------}
   ACTION List_inordre ( N , Head , Tail )
   SOIT
       N : ARB DE ( ENTIER , BOOLEEN ) ;
       Head , Tail , Maillon : LISTE DE ENTIER ;
      
   DEBUT
       SI N <> NIL
           APPEL List_inordre ( FG ( N ) , Head , Tail ) ;
           ALLOUER ( Maillon ) ;
           AFF_VAL ( Maillon , STRUCT ( INFO ( N ) , 1 ) ) ;
           AFF_ADR ( Maillon , NIL ) ;
           SI Head = NIL
               Head := Maillon ;
               Tail := Head ;
              
           SINON
               AFF_ADR ( Tail , Maillon ) ;
               Tail := Maillon ;
              
           FINSI ;
           APPEL List_inordre ( FD ( N ) , Head , Tail ) ;
          
       FINSI
   FIN
  {--------------------------------------------------------------------}
   FONCTION Verifier_arb ( Noeud ) : BOOLEEN
   SOIT
       Noeud : ARB DE ( ENTIER , BOOLEEN ) ;
       Head , Next : LISTE DE ENTIER ;
       Error : BOOLEEN ;
      
   DEBUT
       Head := NIL ;
       APPEL List_inordre ( Noeud , Head , NIL ) ;
       Error := FAUX ;
       TANTQUE ( ( Head <> NIL ) ET ( Error = FAUX ) ) :
           Next := SUIVANT ( Head ) ;
           SI Next <> NIL
               SI VALEUR ( Head ) >= VALEUR ( Next ) :
                   Error := VRAI ;
                  
               FINSI
           FINSI ;
           Head := SUIVANT ( Head ) ;
          
       FINTANTQUE ;
       Verifier_arb := NON Error ;
      
   FIN
  {--------------------------------------------------------------------}
   ACTION Iter_stack ( P , Trav , Tail )
   SOIT
       P , Temp : PILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       Trav , Maillon , Tail : LISTE DE ENTIER ;
       N : ARB DE ( ENTIER , BOOLEEN ) ;
       S : STRUCTURE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       CREERPILE ( Temp ) ;
       TANTQUE PILEVIDE ( P ) = FAUX
           DEPILER ( P , N ) ;
           S := INFO ( N ) ;
           SI STRUCT ( S , 2 ) = FAUX
               AFF_STRUCT ( S , 2 , VRAI ) ;
               AFF_INFO ( N , S ) ;
               ALLOUER ( Maillon ) ;
               AFF_VAL ( Maillon , STRUCT ( S , 1 ) ) ;
               AFF_ADR ( Maillon , NIL ) ;
               SI Trav = NIL
                   Trav := Maillon ;
                   Tail := Trav ;
                  
               SINON
                   AFF_ADR ( Tail , Maillon ) ;
                   Tail := Maillon ;
                  
               FINSI
           FINSI ;
           EMPILER ( Temp , N ) ;
          
       FINTANTQUE ;
       TANTQUE PILEVIDE ( Temp ) = FAUX
           DEPILER ( Temp , N ) ;
           EMPILER ( P , N ) ;
          
       FINTANTQUE
   FIN
  {--------------------------------------------------------------------}
   FONCTION Verif_branche_g ( R ) : LISTE DE ENTIER
   SOIT
       R , N : ARB DE ( ENTIER , BOOLEEN ) ;
       P : PILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       Trav1 , Tail : LISTE DE ENTIER ;
      
   DEBUT
       N := R ;
       Trav1 := NIL ;
       Tail := NIL ;
       SI N <> NIL
           CREERPILE ( P ) ;
           TANTQUE ( ( PILEVIDE ( P ) = FAUX ) OU ( N <> NIL ) ) :
               TANTQUE N <> NIL :
                   EMPILER ( P , N ) ;
                   SI ( ( FG ( N ) = NIL ) ET ( FD ( N ) <> NIL ) ) :
                       N := FD ( N ) ;
                       EMPILER ( P , N ) ;
                      
                   SINON
                       N := FG ( N ) ;
                      
                   FINSI
               FINTANTQUE ;
              /* inserer les noueds trouver dans la pile dans la liste*/
              /* utiliser visited pour eviter la repitision*/
               APPEL Iter_stack ( P , Trav1 , Tail ) ;
               DEPILER ( P , N ) ;
               N := FD ( N ) ;
              
           FINTANTQUE
       FINSI ;
       Verif_branche_g := Trav1 ;
      
   FIN
  {--------------------------------------------------------------------}
   FONCTION Verif_branche_d ( R ) : LISTE DE ENTIER
   SOIT
       R , N : ARB DE ( ENTIER , BOOLEEN ) ;
       P : PILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       Trav3 , Tail : LISTE DE ENTIER ;
      
   DEBUT
       N := R ;
       Trav3 := NIL ;
       Tail := NIL ;
       SI N <> NIL
           CREERPILE ( P ) ;
           TANTQUE ( ( PILEVIDE ( P ) = FAUX ) OU ( N <> NIL ) ) :
               TANTQUE N <> NIL :
                   EMPILER ( P , N ) ;
                   SI ( ( FD ( N ) = NIL ) ET ( FG ( N ) <> NIL ) ) :
                       N := FG ( N ) ;
                       EMPILER ( P , N ) ;
                      
                   SINON
                       N := FD ( N ) ;
                      
                   FINSI
               FINTANTQUE ;
              /* inserer les noueds trouver dans la pile dans la liste*/
              /* utiliser visited pour eviter la repitision*/
               APPEL Iter_stack ( P , Trav3 , Tail ) ;
               DEPILER ( P , N ) ;
               N := FG ( N ) ;
              
           FINTANTQUE
       FINSI ;
       Verif_branche_d := Trav3 ;
      
   FIN
  {--------------------------------------------------------------------}
   ACTION Clear_visited ( R )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
       S : STRUCTURE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI R <> NIL
           APPEL Clear_visited ( FG ( R ) ) ;
           APPEL Clear_visited ( FD ( R ) ) ;
           S := INFO ( R ) ;
           AFF_STRUCT ( S , 2 , FAUX ) ;
           AFF_INFO ( R , S ) ;
          
       FINSI
   FIN
  {--------------------------------------------------------------------}
   FONCTION Children_visited ( R ) : BOOLEEN
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI Feuille ( R ) = VRAI
           Children_visited := VRAI ;
          
       SINON
           SI ( ( FG ( R ) <> NIL ) ET ( FD ( R ) = NIL ) )
               Children_visited := STRUCT ( INFO ( FG ( R ) ) , 2 ) ;
              
           SINON
               SI ( ( FG ( R ) = NIL ) ET ( FD ( R ) <> NIL ) )
                   Children_visited := STRUCT ( INFO ( FD ( R ) ) , 2 ) ;
                  
               SINON
                   Children_visited := ( ( STRUCT ( INFO ( FG ( R ) ) , 2 ) ) ET ( STRUCT ( INFO ( FD ( R ) ) , 2 ) )
                   ) ;
                  
               FINSI
           FINSI
       FINSI
   FIN
  {--------------------------------------------------------------------}
   ACTION Trav_leaf_gauche ( R , Trav2 , Tail )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
       Trav2 , Tail , Maillon : LISTE DE ENTIER ;
       Ignore , Temp1 , Temp2 : BOOLEEN ;
       S : STRUCTURE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI R <> NIL
           Ignore := FAUX ;
           SI FG ( R ) = NIL
               Temp1 := VRAI ;
              
           SINON
               Temp1 := STRUCT ( INFO ( FG ( R ) ) , 2 ) ;
              
           FINSI ;
           SI FD ( R ) = NIL
               Temp2 := VRAI ;
              
           SINON
               Temp2 := STRUCT ( INFO ( FD ( R ) ) , 2 ) ;
              
           FINSI ;
           APPEL Trav_leaf_gauche ( FG ( R ) , Trav2 , Tail ) ;
           APPEL Trav_leaf_gauche ( FD ( R ) , Trav2 , Tail ) ;
           SI FG ( R ) <> NIL
               SI Temp1 <> STRUCT ( INFO ( FG ( R ) ) , 2 )
                   Ignore := VRAI ;
                  
               SINON
                   SI FD ( R ) <> NIL
                       SI Temp2 <> STRUCT ( INFO ( FD ( R ) ) , 2 )
                           Ignore := VRAI ;
                          
                       SINON
                           Ignore := FAUX ;
                          
                       FINSI
                   SINON
                       Ignore := FAUX ;
                      
                   FINSI
               FINSI
           SINON
               SI FD ( R ) <> NIL
                   SI Temp2 <> STRUCT ( INFO ( FD ( R ) ) , 2 )
                       Ignore := VRAI ;
                      
                   SINON
                       Ignore := FAUX ;
                      
                   FINSI
               SINON
                   Ignore := FAUX ;
                  
               FINSI
           FINSI ;
           Temp1 := ( ( Feuille ( R ) = VRAI ) ET ( STRUCT ( INFO ( R ) , 2 ) = FAUX ) ) ;
           Temp2 := ( ( STRUCT ( INFO ( R ) , 2 ) = FAUX ) ET ( Children_visited ( R ) = VRAI ) ) ;
           SI ( ( Ignore = FAUX ) ET ( ( Temp1 = VRAI ) OU ( Temp2 = VRAI ) ) ) :
               S := INFO ( R ) ;
               AFF_STRUCT ( S , 2 , VRAI ) ;
               AFF_INFO ( R , S ) ;
               ALLOUER ( Maillon ) ;
               AFF_VAL ( Maillon , STRUCT ( S , 1 ) ) ;
               AFF_ADR ( Maillon , NIL ) ;
               SI Trav2 = NIL
                   Trav2 := Maillon ;
                   Tail := Trav2 ;
                  
               SINON
                   AFF_ADR ( Tail , Maillon ) ;
                   Tail := Maillon ;
                  
               FINSI
           FINSI
       FINSI
   FIN
  {--------------------------------------------------------------------}
   FONCTION Leaf_gauche ( R ) : LISTE DE ENTIER
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
       Trav2 , Tail : LISTE DE ENTIER ;
      
   DEBUT
       Trav2 := NIL ;
       Tail := NIL ;
       TANTQUE STRUCT ( INFO ( R ) , 2 ) <> VRAI
           APPEL Trav_leaf_gauche ( R , Trav2 , Tail ) ;
          
       FINTANTQUE ;
       Leaf_gauche := Trav2 ;
      
   FIN
  {--------------------------------------------------------------------}
   ACTION Trav_leaf_droite ( R , Trav4 , Tail )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
       Trav4 , Tail , Maillon : LISTE DE ENTIER ;
       Ignore , Temp1 , Temp2 : BOOLEEN ;
       S : STRUCTURE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI R <> NIL
           Ignore := FAUX ;
           SI FG ( R ) = NIL
               Temp1 := VRAI ;
              
           SINON
               Temp1 := STRUCT ( INFO ( FG ( R ) ) , 2 ) ;
              
           FINSI ;
           SI FD ( R ) = NIL
               Temp2 := VRAI ;
              
           SINON
               Temp2 := STRUCT ( INFO ( FD ( R ) ) , 2 ) ;
              
           FINSI ;
           APPEL Trav_leaf_droite ( FD ( R ) , Trav4 , Tail ) ;
           APPEL Trav_leaf_droite ( FG ( R ) , Trav4 , Tail ) ;
           SI FG ( R ) <> NIL
               SI Temp1 <> STRUCT ( INFO ( FG ( R ) ) , 2 )
                   Ignore := VRAI ;
                  
               SINON
                   SI FD ( R ) <> NIL
                       SI Temp2 <> STRUCT ( INFO ( FD ( R ) ) , 2 )
                           Ignore := VRAI ;
                          
                       SINON
                           Ignore := FAUX ;
                          
                       FINSI
                   SINON
                       Ignore := FAUX ;
                      
                   FINSI
               FINSI
           SINON
               SI FD ( R ) <> NIL
                   SI Temp2 <> STRUCT ( INFO ( FD ( R ) ) , 2 )
                       Ignore := VRAI ;
                      
                   SINON
                       Ignore := FAUX ;
                      
                   FINSI
               SINON
                   Ignore := FAUX ;
                  
               FINSI
           FINSI ;
           Temp1 := ( ( Feuille ( R ) = VRAI ) ET ( STRUCT ( INFO ( R ) , 2 ) = FAUX ) ) ;
           Temp2 := ( ( STRUCT ( INFO ( R ) , 2 ) = FAUX ) ET ( Children_visited ( R ) = VRAI ) ) ;
           SI ( ( Ignore = FAUX ) ET ( ( Temp1 = VRAI ) OU ( Temp2 = VRAI ) ) ) :
               S := INFO ( R ) ;
               AFF_STRUCT ( S , 2 , VRAI ) ;
               AFF_INFO ( R , S ) ;
               ALLOUER ( Maillon ) ;
               AFF_VAL ( Maillon , STRUCT ( S , 1 ) ) ;
               AFF_ADR ( Maillon , NIL ) ;
               SI Trav4 = NIL
                   Trav4 := Maillon ;
                   Tail := Trav4 ;
                  
               SINON
                   AFF_ADR ( Tail , Maillon ) ;
                   Tail := Maillon ;
                  
               FINSI
           FINSI
       FINSI
   FIN
  {--------------------------------------------------------------------}
   FONCTION Leaf_droite ( R ) : LISTE DE ENTIER
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
       Trav4 , Tail : LISTE DE ENTIER ;
      
   DEBUT
       Trav4 := NIL ;
       Tail := NIL ;
       TANTQUE STRUCT ( INFO ( R ) , 2 ) <> VRAI
           APPEL Trav_leaf_droite ( R , Trav4 , Tail ) ;
          
       FINTANTQUE ;
       Leaf_droite := Trav4 ;
      
   FIN
  {---------------------------------------------------------------------}
   FONCTION Comparer_listes ( Temp1 , Temp2 ) : BOOLEEN
   SOIT
       L1 , L2 , Temp1 , Temp2 : LISTE DE ENTIER ;
       Error : BOOLEEN ;
      
   DEBUT
       Error := FAUX ;
       L1 := Temp1 ;
       L2 := Temp2 ;
       TANTQUE ( ( L1 <> NIL ) ET ( L2 <> NIL ) ET ( Error = FAUX ) ) :
           SI VALEUR ( L1 ) <> VALEUR ( L2 )
               Error := VRAI ;
              
           FINSI ;
           L1 := SUIVANT ( L1 ) ;
           L2 := SUIVANT ( L2 ) ;
          
       FINTANTQUE ;
       SI ( ( L1 <> NIL ) OU ( L2 <> NIL ) OU ( Error = VRAI ) ) :
           Comparer_listes := FAUX ;
          
       SINON
           Comparer_listes := VRAI ;
          
       FINSI
   FIN
  {----------------------------------------------------------------------}
   FONCTION Verif_leaf_trav_g ( N , Verif2 , Tail ) : ARB DE ( ENTIER , BOOLEEN ) ;
   SOIT
       N , Adrg , Adrd : ARB DE ( ENTIER , BOOLEEN ) ;
       Verif2 , Tail , Maillon : LISTE DE ENTIER ;
      
   DEBUT
       SI N <> NIL
           SI Feuille ( N )
               ALLOUER ( Maillon ) ;
               AFF_VAL ( Maillon , STRUCT ( INFO ( N ) , 1 ) ) ;
               AFF_ADR ( Maillon , NIL ) ;
               SI Verif2 = NIL
                   Verif2 := Maillon ;
                   Tail := Verif2 ;
                  
               SINON
                   AFF_ADR ( Tail , Maillon ) ;
                   Tail := Maillon ;
                  
               FINSI ;
               LIBERERNOEUD ( N ) ;
               N := NIL ;
              
           SINON
               Adrg := Verif_leaf_trav_g ( FG ( N ) , Verif2 , Tail ) ;
               AFF_FG ( N , Adrg ) ;
               Adrd := Verif_leaf_trav_g ( FD ( N ) , Verif2 , Tail ) ;
               AFF_FD ( N , Adrd ) ;
              
           FINSI
       FINSI ;
       Verif_leaf_trav_g := N ;
      
   FIN
  {----------------------------------------------------------------------}
   FONCTION Verif_leaf_g ( N ) : LISTE DE ENTIER
   SOIT
       N : ARB DE ( ENTIER , BOOLEEN ) ;
       Verif2 , Tail : LISTE DE ENTIER ;
      
   DEBUT
       Verif2 := NIL ;
       Tail := NIL ;
       TANTQUE N <> NIL
           N := Verif_leaf_trav_g ( N , Verif2 , Tail ) ;
          
       FINTANTQUE ;
       Verif_leaf_g := Verif2 ;
      
   FIN
  {----------------------------------------------------------------------}
   FONCTION Verif_leaf_trav_d ( N , Verif2 , Tail ) : ARB DE ( ENTIER , BOOLEEN ) ;
   SOIT
       N , Adrg , Adrd : ARB DE ( ENTIER , BOOLEEN ) ;
       Verif2 , Tail , Maillon : LISTE DE ENTIER ;
      
   DEBUT
       SI N <> NIL
           SI Feuille ( N )
               ALLOUER ( Maillon ) ;
               AFF_VAL ( Maillon , STRUCT ( INFO ( N ) , 1 ) ) ;
               AFF_ADR ( Maillon , NIL ) ;
               SI Verif2 = NIL
                   Verif2 := Maillon ;
                   Tail := Verif2 ;
                  
               SINON
                   AFF_ADR ( Tail , Maillon ) ;
                   Tail := Maillon ;
                  
               FINSI ;
               LIBERERNOEUD ( N ) ;
               N := NIL ;
              
           SINON
               Adrd := Verif_leaf_trav_d ( FD ( N ) , Verif2 , Tail ) ;
               AFF_FD ( N , Adrd ) ;
               Adrg := Verif_leaf_trav_d ( FG ( N ) , Verif2 , Tail ) ;
               AFF_FG ( N , Adrg ) ;
              
           FINSI
       FINSI ;
       Verif_leaf_trav_d := N ;
      
   FIN
  {----------------------------------------------------------------------}
   FONCTION Verif_leaf_d ( N ) : LISTE DE ENTIER
   SOIT
       N : ARB DE ( ENTIER , BOOLEEN ) ;
       Verif2 , Tail : LISTE DE ENTIER ;
      
   DEBUT
       Verif2 := NIL ;
       Tail := NIL ;
       TANTQUE N <> NIL
           N := Verif_leaf_trav_d ( N , Verif2 , Tail ) ;
          
       FINTANTQUE ;
       Verif_leaf_d := Verif2 ;
      
   FIN
  {-----------------------------------------------------------------------}
   ACTION Liste_preordre_g ( N , Head , Tail )
   SOIT
       N : ARB DE ( ENTIER , BOOLEEN ) ;
       Head , Tail , Maillon : LISTE DE ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI N <> NIL
           ALLOUER ( Maillon ) ;
           AFF_VAL ( Maillon , N ) ;
           AFF_ADR ( Maillon , NIL ) ;
           SI Head = NIL
               Head := Maillon ;
               Tail := Head ;
              
           SINON
               AFF_ADR ( Tail , Maillon ) ;
               Tail := Maillon ;
              
           FINSI ;
           APPEL Liste_preordre_g ( FG ( N ) , Head , Tail ) ;
           APPEL Liste_preordre_g ( FD ( N ) , Head , Tail ) ;
          
       FINSI
   FIN
  {-----------------------------------------------------------------------}
   FONCTION Branche_gauche ( N ) : LISTE DE ENTIER
   SOIT
       N , Temp : ARB DE ( ENTIER , BOOLEEN ) ;
       T : LISTE DE ARB DE ( ENTIER , BOOLEEN ) ;
       P : PILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       Trav1 , Tail , Maillon : LISTE DE ENTIER ;
      
   DEBUT
       T := NIL ;
       Trav1 := NIL ;
       APPEL Liste_preordre_g ( N , T , NIL ) ;
       TANTQUE T <> NIL
           TANTQUE NON Feuille ( VALEUR ( T ) )
               EMPILER ( P , VALEUR ( T ) ) ;
               T := SUIVANT ( T ) ;
              
           FINTANTQUE ;
           EMPILER ( P , VALEUR ( T ) ) ;
           TANTQUE NON PILEVIDE ( P )
               DEPILER ( P , Temp ) ;
               ALLOUER ( Maillon ) ;
               AFF_VAL ( Maillon , STRUCT ( INFO ( Temp ) , 1 ) ) ;
               AFF_ADR ( Maillon , NIL ) ;
               SI Trav1 = NIL
                   Trav1 := Maillon ;
                   Tail := Trav1 ;
                  
               SINON
                   AFF_ADR ( Tail , Maillon ) ;
                   Tail := Maillon ;
                  
               FINSI ;
              
           FINTANTQUE ;
           T := SUIVANT ( T ) ;
          
       FINTANTQUE ;
       Branche_gauche := Trav1 ;
      
   FIN
  {-----------------------------------------------------------------------}
   ACTION Liste_preordre_d ( N , Head , Tail )
   SOIT
       N : ARB DE ( ENTIER , BOOLEEN ) ;
       Head , Tail , Maillon : LISTE DE ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       SI N <> NIL
           ALLOUER ( Maillon ) ;
           AFF_VAL ( Maillon , N ) ;
           AFF_ADR ( Maillon , NIL ) ;
           SI Head = NIL
               Head := Maillon ;
               Tail := Head ;
              
           SINON
               AFF_ADR ( Tail , Maillon ) ;
               Tail := Maillon ;
              
           FINSI ;
           APPEL Liste_preordre_d ( FD ( N ) , Head , Tail ) ;
           APPEL Liste_preordre_d ( FG ( N ) , Head , Tail ) ;
          
       FINSI
   FIN
  {-----------------------------------------------------------------------}
   FONCTION Branche_droite ( N ) : LISTE DE ENTIER
   SOIT
       N , Temp : ARB DE ( ENTIER , BOOLEEN ) ;
       T : LISTE DE ARB DE ( ENTIER , BOOLEEN ) ;
       P : PILE DE ARB DE ( ENTIER , BOOLEEN ) ;
       Trav1 , Tail , Maillon : LISTE DE ENTIER ;
      
   DEBUT
       T := NIL ;
       Trav1 := NIL ;
       APPEL Liste_preordre_d ( N , T , NIL ) ;
       TANTQUE T <> NIL
           TANTQUE NON Feuille ( VALEUR ( T ) )
               EMPILER ( P , VALEUR ( T ) ) ;
               T := SUIVANT ( T ) ;
              
           FINTANTQUE ;
           EMPILER ( P , VALEUR ( T ) ) ;
           TANTQUE NON PILEVIDE ( P )
               DEPILER ( P , Temp ) ;
               ALLOUER ( Maillon ) ;
               AFF_VAL ( Maillon , STRUCT ( INFO ( Temp ) , 1 ) ) ;
               AFF_ADR ( Maillon , NIL ) ;
               SI Trav1 = NIL
                   Trav1 := Maillon ;
                   Tail := Trav1 ;
                  
               SINON
                   AFF_ADR ( Tail , Maillon ) ;
                   Tail := Maillon ;
                  
               FINSI ;
              
           FINTANTQUE ;
           T := SUIVANT ( T ) ;
          
       FINTANTQUE ;
       Branche_droite := Trav1 ;
      
   FIN
  {----------------------------------------------------------------------------}
   ACTION Info1 ( R )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       ECRIRE ( '' ) ;
       ECRIRE ( 'le parcour inordre du arbre 1 : ' ) ;
       ECRIRE ( '' ) ;
       APPEL Inordre ( R ) ;
       ECRIRE ( 'est ce que l arbre est bien construit : ' ) ;
       ECRIRE ( Verifier_arb ( R ) ) ;
       ECRIRE ( '' ) ;
       Trav1 := Branche_gauche ( R ) ;
       Verif1 := Verif_branche_g ( R ) ;
       APPEL Clear_visited ( R ) ;
       Trav2 := Leaf_gauche ( R ) ;
       Verif2 := Verif_leaf_g ( R ) ;
       ECRIRE ( 'traverse 1 : branche par branche du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav1 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 1 : branche par branche du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif1 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav1 , Verif1 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 2 : feuille par feuille du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav2 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 2 : feuille par feuille du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif2 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav2 , Verif2 ) ) ;
       ECRIRE ( '' ) ;
      
   FIN
  {--------------------------------------------------------------------------------------}
   ACTION Info2 ( R )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       ECRIRE ( '' ) ;
       ECRIRE ( 'le parcour inordre du arbre 2 : ' ) ;
       ECRIRE ( '' ) ;
       APPEL Inordre ( R ) ;
       ECRIRE ( 'est ce que l arbre est bien construit : ' ) ;
       ECRIRE ( Verifier_arb ( R ) ) ;
       ECRIRE ( '' ) ;
       Trav3 := Branche_droite ( R ) ;
       Verif3 := Verif_branche_d ( R ) ;
       APPEL Clear_visited ( R ) ;
       Trav4 := Leaf_droite ( R ) ;
       Verif4 := Verif_leaf_d ( R ) ;
       ECRIRE ( 'traverse 3 : branche par branche du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav3 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 3 : branche par branche du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif3 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav3 , Verif3 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 4  : feuille par feuille du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Trav4 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'verification 4 : feuille par feuille du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       APPEL Print_liste ( Verif4 ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav4 , Verif4 ) ) ;
       ECRIRE ( '' ) ;
      
   FIN
  {------------------------------------------------------------------------------------}
   ACTION Info_impair ( R )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       ECRIRE ( 'est ce que l arbre est bien construit : ' ) ;
       ECRIRE ( Verifier_arb ( R ) ) ;
       ECRIRE ( '' ) ;
       Trav1 := Branche_gauche ( R ) ;
       Verif1 := Verif_branche_g ( R ) ;
       APPEL Clear_visited ( R ) ;
       Trav2 := Leaf_gauche ( R ) ;
       Verif2 := Verif_leaf_g ( R ) ;
       ECRIRE ( 'traverse 1 : branche par branche du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav1 , Verif1 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 2 : feuille par feuille du gauche a droite' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav2 , Verif2 ) ) ;
       ECRIRE ( '' ) ;
      
   FIN
  {-------------------------------------------------------------------------------------}
   ACTION Info_pair ( R )
   SOIT
       R : ARB DE ( ENTIER , BOOLEEN ) ;
      
   DEBUT
       ECRIRE ( 'est ce que l arbre est bien construit : ' ) ;
       ECRIRE ( Verifier_arb ( R ) ) ;
       ECRIRE ( '' ) ;
       Trav3 := Branche_droite ( R ) ;
       Verif3 := Verif_branche_d ( R ) ;
       APPEL Clear_visited ( R ) ;
       Trav4 := Leaf_droite ( R ) ;
       Verif4 := Verif_leaf_d ( R ) ;
       ECRIRE ( 'traverse 3 : branche par branche du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav3 , Verif3 ) ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'traverse 4  : feuille par feuille du droite a gauche' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( 'comparaison des deux listes : ' ) ;
       ECRIRE ( '' ) ;
       ECRIRE ( Comparer_listes ( Trav4 , Verif4 ) ) ;
       ECRIRE ( '' ) ;
      
   FIN