// WINDING_1 ;
c_user  = 0.001;            
c_min  = 0.001*Min[lr,lz];            
c_max  = 0.4995*Min[lr,lz];            
dr = Max[c_min,c_user];            
narc_cond= 2 + 1*Ceil(1*dr/TOL) ;


i = 0 ;
es_extra_mem = 0 ;
For iz In {1:Nz}
    For ir In {1:Nr}
        i = i+1;
        // p1 = p0+4*i-3 ;
        // p2 = p0+4*i-2 ;
        // p3 = p0+4*i-1 ;
        // p4 = p0+4*i ;
        p1  = p0+12*i-11 ;
        p2  = p0+12*i-10 ;
        p3  = p0+12*i-9 ;
        p4 	= p0+12*i-8 ;
        p5 	= p0+12*i-7 ;
        p6 	= p0+12*i-6 ;
        p7 	= p0+12*i-5 ;
        p8 	= p0+12*i-4 ;
        p9 	= p0+12*i-3 ;
        p10 = p0+12*i-2 ;
        p11 = p0+12*i-1 ;
        p12 = p0+12*i-0 ;

        rm = Ro+ei+lr/2+(ir-1)*(lr+2*ei) ;
        // zm = Zo+ei+lz/2+(iz-1)*(lz+2*ei+es) ;
		zm = Zo+ei+lz/2+(iz-1)*(lz+2*ei+es) + es_extra[iz-1] + es_extra_mem  ;
		
		
     // Point(p1) = {rm-lr/2	 , zm-lz/2, 0, lcc} ;     
		Point(p1) = {rm-lr/2 + dr, zm-lz/2 + dr, 0, lcc} ;     
		Point(p2) = {rm-lr/2 + dr, zm-lz/2 + 0 , 0, lcc} ;     
		Point(p3) = {rm-lr/2 + 0 , zm-lz/2 + dr, 0, lcc} ;     
		
	 // Point(p2) = {rm+lr/2	 , zm-lz/2, 0, lcc} ;     
		Point(p4) = {rm+lr/2 - dr, zm-lz/2 + dr, 0, lcc} ;     
		Point(p5) = {rm+lr/2 - dr, zm-lz/2 + 0 , 0, lcc} ;     
		Point(p6) = {rm+lr/2 - 0 , zm-lz/2 + dr, 0, lcc} ;     
		
     // Point(p3) = {rm+lr/2	 , zm+lz/2, 0, lcc} ;     
		Point(p7) = {rm+lr/2 - dr, zm+lz/2 - dr, 0, lcc} ;     
		Point(p8) = {rm+lr/2 - dr, zm+lz/2 - 0 , 0, lcc} ;     
		Point(p9) = {rm+lr/2 - 0 , zm+lz/2 - dr, 0, lcc} ;     
		
     // Point(p4) = {rm-lr/2	 , zm+lz/2, 0, lcc} ;     
		Point(p10)= {rm-lr/2 + dr, zm+lz/2 - dr, 0, lcc} ;     
		Point(p11)= {rm-lr/2 + dr, zm+lz/2 - 0 , 0, lcc} ;     
		Point(p12)= {rm-lr/2 + 0 , zm+lz/2 - dr, 0, lcc} ;     
		
        // l1 = l0+4*i-3 ;
        // l2 = l0+4*i-2 ;
        // l3 = l0+4*i-1 ;
        // l4 = l0+4*i ;
		
        l1 = l0+8*i-7 ;
        l2 = l0+8*i-6 ;
        l3 = l0+8*i-5 ;
        l4 = l0+8*i-4 ;
		l5 = l0+8*i-3 ;
        l6 = l0+8*i-2 ;
        l7 = l0+8*i-1 ;
        l8 = l0+8*i-0 ;
		
        // Line(l1) = {p1,p2} ;
        // Line(l2) = {p2,p3} ;
        // Line(l3) = {p3,p4} ;
        // Line(l4) = {p4,p1} ;
		
		Line(l1) 	= {p2,	 	p5} ;
        Line(l3) 	= {p6,	 	p9} ;
        Line(l5) 	= {p8,	 	p11} ;
        Line(l7) 	= {p12,	 	p3} ;
        


		Transfinite Curve {l1} = nrc_cond;
		Transfinite Curve {l3} = nzc_cond;
		Transfinite Curve {l5} = nrc_cond;
		Transfinite Curve {l7} = nzc_cond;
		

		
		Circle(l2) 	= {p6 ,p4,	p5} ;
		Circle(l4) 	= {p8 ,p7,	p9} ;
		Circle(l6) 	= {p12,p10,	p11} ;
		Circle(l8) 	= {p3 ,p1,	p2} ;

		
		Delete{ Point{p1};Point{p4}; Point{p7}; Point{p10}; }

		Transfinite Curve {l2} = narc_cond;
		Transfinite Curve {l4} = narc_cond;
		Transfinite Curve {l6} = narc_cond;
		Transfinite Curve {l8} = narc_cond;
		
		
        ll1 = ll0+2*i-1 ;
        ps1 = ll0+2*i ;
        // Line Loop(ll1) = {l1,l2,l3,l4} ;
		Line Loop(ll1) = {l1,l2,l3,l4,l5,l6,l7,l8} ;
        Plane Surface(ps1) = {ll1} ;
        // Plane Surface(ps1) = {ll1} ;
        llcond[ir-1] = -ll1;
        //Transfinite Surface {ps1} = {p1,p2,p3,p4};
        //Recombine Surface {ps1} ;
        //phys1 = phys0+i ;
        phys1 = phys0+i ;
		//Physical Surface(Sprintf("COIL_%03g",i),phys1) = {ps1};	// conductor 
		Physical Surface(Sprintf("COIL_%03g",i),phys1) = {ps1};	// conductor 
        phyl1 = phyl0+i ;
        // Physical Line(Sprintf("COIL_%03g_bnd",i),phyl1) = {l1,l2,l3,l4};	// frontera conductor 
		Physical Line(Sprintf("COIL_%03g_bnd",i),phyl1) = {l1,l2,l3,l4,l5,l6,l7,l8} ;	// frontera conductor 
    EndFor
    p1 = ioffset+p0+4*iz-3 ;
    p2 = ioffset+p0+4*iz-2 ;
    p3 = ioffset+p0+4*iz-1 ;
    p4 = ioffset+p0+4*iz ;
    rl = Ro ;
    // zb = Zo+(iz-1)*(lz+2*ei+es) ;
	zb = zm - (lz/2 + ei);
    Point(p1) = {rl, zb, 0, lci} ;     
    Point(p2) = {rl+Hr, zb, 0, lci} ;     
    Point(p3) = {rl+Hr, zb+lz+2*ei, 0, lci} ;     
    Point(p4) = {rl, zb+lz+2*ei, 0, lci} ;     
    l1 = ioffset+l0+4*iz-3 ;
    l2 = ioffset+l0+4*iz-2 ;
    l3 = ioffset+l0+4*iz-1 ;
    l4 = ioffset+l0+4*iz ;
    Line(l1) = {p1,p2} ;
    Line(l2) = {p2,p3} ;
    Line(l3) = {p3,p4} ;
    Line(l4) = {p4,p1} ;
    

		
	Transfinite Curve {l1} = nrc_intra_disk;
	Transfinite Curve {l2} = nzc_intra_disk;
	Transfinite Curve {l3} = nrc_intra_disk;
	Transfinite Curve {l4} = nzc_intra_disk;
	
    
    ll1 = ioffset+ll0+2*iz-1 ;
    ps1 = ioffset+ll0+2*iz ;
    Line Loop(ll1) = {l1,l2,l3,l4} ;
    Plane Surface(ps1) = {ll1,llcond[]} ;
    //Recombine Surface {ps1} ;
    lldisc[iz-1] = -ll1;
    phys1 = ioffset+phys0+iz ;
    Physical Surface(Sprintf("Insulation_%g",iz),phys1) = {ps1};	// aislador
	
	es_extra_mem = es_extra_mem + es_extra[iz-1];	
EndFor


// / To test ( YA FUNCIONA, PERO SE VA A REEMPLAZAR POR RUPOS DE DEVANADOS
// ppdoffset	= 30000000;
// LIC_FLAG  	= 1;
// LIC_Nzpos 	= 0.5*Nz ;
LIC_Nzpos 	= 2*Nz ;	
If (LIC_FLAG == 1)
	LIC_Nzpos 	= 0.5*Nz ;	
EndIf


i = 0;
For izp In {1:Nz-1}

	p1 = ioffset+p0+4*izp-3 + 2;    // OK
	p2 = ioffset+p0+4*izp-2 + 2;    // OK
	p3 = ioffset+p0+4*izp-1 + 2;    // OK
	p4 = ioffset+p0+4*izp-0 + 2;    // OK
	
	l1 = ioffset+l0+4*izp-3 + 2;
	l2 = ioffset+l0+4*izp-2 + ppoffset;
	l3 = ioffset+l0+4*izp-1 + 2;
	l4 = ioffset+l0+4*izp-0 + ppoffset;
	

	ll1 = ioffset+ll0+2*izp-1 + ppdoffset ;
	ps1 = ioffset+ll0+2*izp + ppoffset;
	phys1 = ioffset+phys0+izp + ppdoffset ;
	If (izp != LIC_Nzpos)
		i = i+1;
	
		Line(l2) = {p2,p3} ;
		Line(l4) = {p4,p1} ;


        Transfinite Curve {l2} = nzc_inter_disk ;
        Transfinite Curve {l4} = nzc_inter_disk ;
	
		
		Line Loop(ll1) = {-l1,l2,-l3,l4} ;
		Plane Surface(ps1) = {ll1} ;
		lldisc_presspan[i-1] = -ll1;
		Physical Surface(Sprintf("Insulation_interdisk_%g",izp),phys1) = {ps1};	// aislación presspan entre discos
		// Transfinite Surface{ps1} = {p1,p2,p3,p4};
	EndIf
		
EndFor
