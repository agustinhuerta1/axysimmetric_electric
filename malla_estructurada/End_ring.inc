/////////// End Ring V1
// esroffset =  40000000 ;
 // Nesr  = 0;
EndRing_r  =  {  } ;
EndRing_z  =  {  } ;
EndRing_R  =  {  } ;
EndRing_H  =  {  } ;
EndRing_c  =  {  } ;
EndRing_dir_r  =  {  } ;
EndRing_dir_z  =  {  } ;

i = 0 ;
For iesr In {1:N_end_ring}
    i = i + 1 ;
    
    r0	= EndRing_r[iesr-1];
    z0	= -0.5*Core_Z+EndRing_z[iesr-1];
    R	= EndRing_R[iesr-1];
    H	= EndRing_H[iesr-1];
    // rc	= EndRing_c[iesr-1];
	rc = 10E-3;
	
	
	nrc_EndRing = Ceil(0.5*R/ei);
	nzc_EndRing = Ceil(0.5*H/ei);
	narc_EndRing= Ceil(rc/ei);
		
        p1  = p0+end_ring_offset+10*i-9 ;
        p2  = p0+end_ring_offset+10*i-8 ;
        p3  = p0+end_ring_offset+10*i-7 ;
        p4 	= p0+end_ring_offset+10*i-6 ;
        p5 	= p0+end_ring_offset+10*i-5 ;
        p6 	= p0+end_ring_offset+10*i-4 ;
        p7 	= p0+end_ring_offset+10*i-3 ;
        p8 	= p0+end_ring_offset+10*i-2 ;
        p9 	= p0+end_ring_offset+10*i-1 ;
        p10 = p0+end_ring_offset+10*i-0 ;
		
		A = EndRing_R[iesr-1];
		B = EndRing_H[iesr-1];
		C = EndRing_c[iesr-1];
		nr = EndRing_dir_r[iesr-1];
		nz = -EndRing_dir_z[iesr-1];

		Point(p1) = {r0 - nr*(rc+C) 	, z0 - nz*(B-(rc+C)) , 0, lcc} ;     
		Point(p2) = {r0 - nr*(rc) 	 	, z0 - nz*(B-(rc+C)) 	, 0, lcc} ;     
		Point(p3) = {r0 - nr*(rc) 	 	, z0 + 0	, 0, lcc} ;     
		Point(p4) = {r0 - nr*(rc+C) 	, z0 + 0	, 0, lcc} ;     
		
		Point(p5) = {r0 + 0 			, z0 + nz*(rc)	, 0, lcc} ;     
		Point(p6) = {r0 + nr*(A-(C+rc)) , z0 + nz*(rc)	, 0, lcc} ;     
		Point(p7) = {r0 + nr*(A-(C+rc)) , z0 + nz*(rc+C)	, 0, lcc} ;     
		Point(p8) = {r0 + 0 			, z0 + nz*(rc+C)	, 0, lcc} ;     

		Point(p9) = {r0   , z0 	, 0, lcc} ;      
		
        l1 = l0+end_ring_offset+10*i-9 ;
        l2 = l0+end_ring_offset+10*i-8 ;
        l3 = l0+end_ring_offset+10*i-7 ;
        l4 = l0+end_ring_offset+10*i-6 ;
		l5 = l0+end_ring_offset+10*i-5 ;
        l6 = l0+end_ring_offset+10*i-4 ;
        l7 = l0+end_ring_offset+10*i-3 ;
        l8 = l0+end_ring_offset+10*i-2 ;
		l9 = l0+end_ring_offset+10*i-1 ;
		l10= l0+end_ring_offset+10*i-0 ;
		

		Line(l1) 	= {p1,	 	p2} ;
        Line(l2) 	= {p2,	 	p3} ;
        Line(l3) 	= {p3,	 	p4} ;
        Line(l4) 	= {p4,	 	p1} ;
		
		Line(l5) 	= {p5,	 	p6} ;
        Line(l6) 	= {p6,	 	p7} ;
        Line(l7) 	= {p7,	 	p8} ;
        Line(l8) 	= {p8,	 	p5} ;

		Transfinite Curve {l1} = nrc_EndRing;
		Transfinite Curve {l3} = nrc_EndRing;
		Transfinite Curve {l6} = nrc_EndRing;
		Transfinite Curve {l8} = nrc_EndRing;
		
		Transfinite Curve {l2} = nzc_EndRing;
		Transfinite Curve {l4} = nzc_EndRing;
		
		Transfinite Curve {l5} = nrc_EndRing;
		Transfinite Curve {l7} = nrc_EndRing;
		
		Circle(l9) 		= {p3 ,p9,	p5} ;
		Circle(l10) 	= {p4 ,p9,	p8} ;

		Transfinite Curve {l9}  = 4 + narc_EndRing ;
		Transfinite Curve {l10} = 4 + narc_EndRing ;
		
        // Delete{ Point{p9}; Point{p10}; }
		Delete{ Point{p9}; }
		
		
        ll1 	= ll0+2*i	+ 1*end_ring_offset ;
        ps1 	= ll0+2*i 	+ 1*end_ring_offset;
		
		// Curve Loop(ll1) = {l1,l2,l3,l4,l5,l6,l7,l8} ;
		Curve Loop(ll1) = {l1,l2,l9,l5,l6,l7,l10,l4} ;
		
        Plane Surface(ps1) = {ll1} ;
        ll_end_ring[iesr-1] =  -ll1;
        // Recombine Surface {ps1} ;
        phys1 	= phys0+2*i + 1*end_ring_offset;
		phyl1 	= phyl0+2*i + 1*end_ring_offset;
		Physical Surface(Sprintf("EndRing%03g",iesr),phys1) = {ps1};	// EndRing 
		// Physical Curve(  Sprintf("EndRing_BND%03g",iesr),phyl1) = {Boundary { Surface { ps1 } ;} };	// EndRing  BND

    

EndFor

If (N_end_ring == 0)
	ll_end_ring[] =  {};
EndIf



