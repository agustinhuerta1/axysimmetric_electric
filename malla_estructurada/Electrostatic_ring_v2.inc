/////////// Electrostatic Ring_v2
// esroffset =  500000 ;
// esr_ins_offset =  300 ;
 // Nesr  = 0;
ESR_r  =  {  } ;
ESR_z  =  {  } ;
ESR_R  =  {  } ;
ESR_H  =  {  } ;
ESR_c  =  {  } ;
ESR_g  =  {  } ;

i = 0 ;
For iesr In {1:Nesr}
    i = i + 1 ;
    
    ro	= ESR_r[iesr-1];
    zo	= -0.5*Core_Z+ESR_z[iesr-1];
    R	= ESR_R[iesr-1];
    H	= ESR_H[iesr-1];
    rc	= ESR_c[iesr-1];
	
	nrc_ESR_COND = Ceil(0.5*R/ei);
	nzc_ESR_COND = Ceil(0.3*H/ei);
		
        p1  = p0+esroffset+24*i-23 ;
        p2  = p0+esroffset+24*i-22 ;
        p3  = p0+esroffset+24*i-21 ;
        p4 	= p0+esroffset+24*i-20 ;
        p5 	= p0+esroffset+24*i-19 ;
        p6 	= p0+esroffset+24*i-18 ;
        p7 	= p0+esroffset+24*i-17 ;
        p8 	= p0+esroffset+24*i-16 ;
        p9 	= p0+esroffset+24*i-15 ;
        p10 = p0+esroffset+24*i-14 ;
        p11 = p0+esroffset+24*i-13 ;
        p12 = p0+esroffset+24*i-12 ;

        p13 = p0+esroffset+24*i-11 ;
        p14 = p0+esroffset+24*i-10 ;
        p15 = p0+esroffset+24*i-9 ;
        p16	= p0+esroffset+24*i-8 ;
        p17	= p0+esroffset+24*i-7 ;
        p18	= p0+esroffset+24*i-6 ;
        p19	= p0+esroffset+24*i-5 ;
        p20	= p0+esroffset+24*i-4 ;
        p21	= p0+esroffset+24*i-3 ;
        p22 = p0+esroffset+24*i-2 ;
        p23 = p0+esroffset+24*i-1 ;
        p24 = p0+esroffset+24*i-0 ;

		ro	= ESR_r[iesr-1];
		zo	= -0.5*Core_Z+ESR_z[iesr-1];
		R	= ESR_R[iesr-1];
		H	= ESR_H[iesr-1];
		rc	= ESR_c[iesr-1];
		dr  = rc;

        rm = ro + 0.5*R;
        zm = zo + 0.5*H;
		
		
     // Point(p1) = {rm-R/2	 , zm-H/2, 0, lcc} ;     
		Point(p1) = {rm-R/2 + dr, zm-H/2 + dr, 0, lcc} ;     
		Point(p2) = {rm-R/2 + dr, zm-H/2 + 0 , 0, lcc} ;     
		Point(p3) = {rm-R/2 + 0 , zm-H/2 + dr, 0, lcc} ;     
		
	 // Point(p2) = {rm+R/2	 , zm-H/2, 0, lcc} ;     
		Point(p4) = {rm+R/2 - dr, zm-H/2 + dr, 0, lcc} ;     
		Point(p5) = {rm+R/2 - dr, zm-H/2 + 0 , 0, lcc} ;     
		Point(p6) = {rm+R/2 - 0 , zm-H/2 + dr, 0, lcc} ;     
		
     // Point(p3) = {rm+R/2	 , zm+H/2, 0, lcc} ;     
		Point(p7) = {rm+R/2 - dr, zm+H/2 - dr, 0, lcc} ;     
		Point(p8) = {rm+R/2 - dr, zm+H/2 - 0 , 0, lcc} ;     
		Point(p9) = {rm+R/2 - 0 , zm+H/2 - dr, 0, lcc} ;     
		
     // Point(p4) = {rm-R/2	 , zm+H/2, 0, lcc} ;     
		Point(p10)= {rm-R/2 + dr, zm+H/2 - dr, 0, lcc} ;     
		Point(p11)= {rm-R/2 + dr, zm+H/2 - 0 , 0, lcc} ;     
		Point(p12)= {rm-R/2 + 0 , zm+H/2 - dr, 0, lcc} ;     
		

        l1 = l0+esroffset+16*i-15 ;
        l2 = l0+esroffset+16*i-14 ;
        l3 = l0+esroffset+16*i-13 ;
        l4 = l0+esroffset+16*i-12 ;
		l5 = l0+esroffset+16*i-11 ;
        l6 = l0+esroffset+16*i-10 ;
        l7 = l0+esroffset+16*i-9 ;
        l8 = l0+esroffset+16*i-8 ;

        l9 = l0+esroffset+16*i-7 ;
        l10= l0+esroffset+16*i-6 ;
        l11= l0+esroffset+16*i-5 ;
        l12= l0+esroffset+16*i-4 ;
		l13= l0+esroffset+16*i-3 ;
        l14= l0+esroffset+16*i-2 ;
        l15= l0+esroffset+16*i-1 ;
        l16= l0+esroffset+16*i-0 ;
		

		Line(l1) 	= {p2,	 	p5} ;
        Line(l3) 	= {p6,	 	p9} ;
        Line(l5) 	= {p8,	 	p11} ;
        Line(l7) 	= {p12,	 	p3} ;
		


		Transfinite Curve {l1} = nrc_ESR_COND;
		Transfinite Curve {l3} = nzc_ESR_COND;
		Transfinite Curve {l5} = nrc_ESR_COND;
		Transfinite Curve {l7} = nzc_ESR_COND;
		
		
		Circle(l2) 	= {p6 ,p4,	p5} ;
		Circle(l4) 	= {p8 ,p7,	p9} ;
		Circle(l6) 	= {p12,p10,	p11} ;
		Circle(l8) 	= {p3 ,p1,	p2} ;

        Delete{ Point{p1}; Point{p4}; Point{p7}; Point{p10}; }
		
		Transfinite Curve {l2} = 4;
		Transfinite Curve {l4} = 4;
		Transfinite Curve {l6} = 4;
		Transfinite Curve {l8} = 4;
		
        ll1 	= ll0+2*i	+ 1*esroffset ;
        ps1 	= ll0+2*i 	+ 1*esroffset;
		
		Curve Loop(ll1) = {l1,l2,l3,l4,l5,l6,l7,l8} ;
		
        Plane Surface(ps1) = {ll1} ;
        llesr[iesr-1] =  -ll1;
        // Recombine Surface {ps1} ;
        phys1 	= phys0+2*i + 1*esroffset;
		phyl1 	= phyl0+2*i + 1*esroffset;
		Physical Surface(Sprintf("ESR%03g",iesr),phys1) = {ps1};	// ESR COND	
		Physical Curve(  Sprintf("ESR_BND%03g",iesr),phyl1) = {Boundary { Surface { ps1 } ;} };	// ESR COND BND

    
    // ESR INSULATION
		rc	= ESR_c[iesr-1];
		dr  = rc + ESR_g[iesr-1];
	
     // Point(p1) = {rm-R/2	 , zm-(H/2 +  ESR_g[iesr-1] ), 0, lcc} ;     
		Point(p13) = {rm-(R/2 + 1*  ESR_g[iesr-1] ) + dr, zm-(H/2 + 1* ESR_g[iesr-1] ) + dr, 0, lcc} ;     
		Point(p14) = {rm-(R/2 + 1*  ESR_g[iesr-1] ) + dr, zm-(H/2 + 1* ESR_g[iesr-1] ) + 0 , 0, lcc} ;     
		Point(p15) = {rm-(R/2 + 1*  ESR_g[iesr-1] ) + 0 , zm-(H/2 + 1* ESR_g[iesr-1] ) + dr, 0, lcc} ;     

	 // Point(p2) = {rm+(R/2 +  2* ESR_g[iesr-1] )	 , zm-(H/2 +  ESR_g[iesr-1] ), 0, lcc} ;     
		Point(p16) = {rm+(R/2 + 1*  ESR_g[iesr-1] ) - dr, zm-(H/2 + 1* ESR_g[iesr-1] ) + dr, 0, lcc} ;     
		Point(p17) = {rm+(R/2 + 1*  ESR_g[iesr-1] ) - dr, zm-(H/2 + 1* ESR_g[iesr-1] ) + 0 , 0, lcc} ;     
		Point(p18) = {rm+(R/2 + 1*  ESR_g[iesr-1] ) - 0 , zm-(H/2 + 1* ESR_g[iesr-1] ) + dr, 0, lcc} ;     

     // Point(p3) = {rm+(R/2 +  2* ESR_g[iesr-1] )	 , zm+(H/2 +  ESR_g[iesr-1] ), 0, lcc} ;     
		Point(p19) = {rm+(R/2 + 1*  ESR_g[iesr-1] ) - dr, zm+(H/2 +1* ESR_g[iesr-1] ) - dr, 0, lcc} ;     
		Point(p20) = {rm+(R/2 + 1*  ESR_g[iesr-1] ) - dr, zm+(H/2 +1* ESR_g[iesr-1] ) - 0 , 0, lcc} ;     
		Point(p21) = {rm+(R/2 + 1*  ESR_g[iesr-1] ) - 0 , zm+(H/2 +1* ESR_g[iesr-1] ) - dr, 0, lcc} ;     

     // Point(p4) = {rm-(R/2 +  2* ESR_g[iesr-1] )	 , zm+(H/2 +  ESR_g[iesr-1] ), 0, lcc} ;     
		Point(p22)= {rm-(R/2 +  1* ESR_g[iesr-1] ) + dr, zm+(H/2 + 1* ESR_g[iesr-1] ) - dr, 0, lcc} ;     
		Point(p23)= {rm-(R/2 +  1* ESR_g[iesr-1] ) + dr, zm+(H/2 + 1* ESR_g[iesr-1] ) - 0 , 0, lcc} ;     
		Point(p24)= {rm-(R/2 +  1* ESR_g[iesr-1] ) + 0 , zm+(H/2 + 1* ESR_g[iesr-1] ) - dr, 0, lcc} ;     

		Line(l9) 	= {p14,	 	p17} ;
        Line(l11) 	= {p18,	 	p21} ;
        Line(l13) 	= {p20,	 	p23} ;
        Line(l15) 	= {p24,	 	p15} ;
		


		Transfinite Curve {l9 } =  nrc_ESR_COND;
		Transfinite Curve {l11} =  nzc_ESR_COND;
		Transfinite Curve {l13} =  nrc_ESR_COND;
		Transfinite Curve {l15} =  nzc_ESR_COND;
		
		
		
		Circle(l10) 	= {p18 ,p16,	p17} ;
		Circle(l12) 	= {p20 ,p19,	p21} ;
		Circle(l14) 	= {p24 ,p22,	p23} ;
		Circle(l16) 	= {p15 ,p13,	p14} ;
		

        
		Delete{ Point{p16}; Point{p19}; Point{p22}; Point{p13};}
        
		Transfinite Curve {l10} = 4;
		Transfinite Curve {l12} = 4;
		Transfinite Curve {l14} = 4;
		Transfinite Curve {l16} = 4;
		
        ll1 	= ll0+2*i	+ 1*esroffset + esr_ins_offset ;
        ps1 	= ll0+2*i 	+ 1*esroffset + esr_ins_offset;
        
		Curve Loop(ll1) = {l9,l10,l11,l12,l13,l14,l15,l16} ;
        Plane Surface(ps1) = {ll1,llesr[iesr-1]} ;
		llesr_ins[iesr-1] =  -ll1;

        phys1 	= phys0+2*i + 1*esroffset + esr_ins_offset;
		phyl1 	= phyl0+2*i + 1*esroffset + esr_ins_offset;
		Physical Surface(Sprintf("ESR_ins%03g",iesr),phys1 ) = {ps1 };	// ESR INSULATION


EndFor

If (Nesr == 0)
	llesr_ins[] =  {};
EndIf



