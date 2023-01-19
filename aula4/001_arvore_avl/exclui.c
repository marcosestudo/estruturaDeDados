// TAVL* TAVL_retira(int x, TAVL *t){      
//    if(!t) return t; 
//    else if(x > t->info){ 
//      t->dir = TAVL_retira(x, t->dir); 
//      if(FB(t) == 2) 
//        if(FB(t->esq) >= 0){ 
//          printf("RSD(%d)\n", t->info); 
//          t = TAVL_rot_dir(t); 
//        }else{ 
//          printf("RED(%d)\n", t->info); 
//          t = TAVL_rot_esq_dir(t); 
//        } 
//    } 
//    else if(x < t->info){ 
//      t->esq = TAVL_retira(x, t->esq); 
//      if(FB(t) == -2) 
//        if(FB(t->dir) <= 0){ 
//          printf("RSE(%d)\n", t->info); 
//          t = TAVL_rot_esq(t); 
//        }else{ 
//          printf("RDE(%d)\n", t->info); 
//          t = TAVL_rot_dir_esq(t); 
//        } 
//    } 
//    else{ 
//      if(t->esq){ 
//        TAVL *p = t->esq; 
//        while(p->dir) p = p->dir; 
//        t->info = p->info; 
//        t->esq = TAVL_retira(p->info, t->esq); 
//        if(FB(t) == -2) 
//          if(FB(t->dir) <= 0){ 
//            printf("RSE(%d)\n", t->info); 
//            t = TAVL_rot_esq(t); 
//          }else{ 
//            printf("RDE(%d)\n", t->info); 
//            t = TAVL_rot_dir_esq(t); 
//          } 
//      }else{ 
//         TAVL *x = t; 
//         t = t->dir; 
//         free(x); 
//         return(t); 
//      } 
//    } 
//    t->alt = calc_alt_retira(t);
//    return t; 
//  }