// Presspan cylinders
// ppoffset= 10000000;
 // Npp  = 0;
PPCyl_R  =  {  } ;
PPCyl_d  =  {  } ;
PPCyl_H  =  {  } ;
PPCyl_z  =  {  } ;
/*
 Python specifies: 
 PPCyl_r={};
 PPCyl_d={};
 PPCyl_H={};
 PPCyl_z={};
 */
 
    
i = 0 ;
        For ip In {1:Npp}
            i = i + 1 ;
            p1 = ppoffset+p0+4*i-3 ;	p2 = ppoffset+p0+4*i-2 ;
            p3 = ppoffset+p0+4*i-1 ;	p4 = ppoffset+p0+4*i ;
            
            R  = PPCyl_R[ip-1];
            dr = PPCyl_d[ip-1];
            z1 = -0.5*Core_Z+PPCyl_z[ip-1];
            z2 = -0.5*Core_Z+PPCyl_z[ip-1] + PPCyl_H[ip-1];
            Point(p1) = {R		, z1 , 0, 16*lci} ;     
            Point(p2) = {R+dr	, z1 , 0, 16*lci} ;     
            Point(p3) = {R+dr	, z2 , 0, 16*lci} ;     
            Point(p4) = {R		, z2 , 0, 16*lci} ;     
            l1 = ppoffset+l0+4*i-3 ;	l2 = ppoffset+l0+4*i-2 ;
            l3 = ppoffset+l0+4*i-1 ;	l4 = ppoffset+l0+4*i ;
            Line(l1) = {p1,p2} ;	Line(l2) = {p2,p3} ;
            Line(l3) = {p3,p4} ;	Line(l4) = {p4,p1} ;
            

			// nrc_presspan = Ceil(PPCyl_d[ip-1]/ei)+1 ;
            nrc_presspan = 2 + Ceil(PPCyl_d[ip-1]/(1.1*TOL));
			// nzc_presspan = Ceil(0.8*PPCyl_H[ip-1]/lz);
            nzc_presspan = Ceil(0.4*PPCyl_H[ip-1]/TOL);

			Transfinite Curve {l1} = nrc_presspan;
			Transfinite Curve {l2} = nzc_presspan;
			Transfinite Curve {l3} = nrc_presspan;
			Transfinite Curve {l4} = nzc_presspan;

            
            ll1 = ppoffset+ll0+2*i-1 ;
            ps1 = ppoffset+ll0+2*i ;
            Line Loop(ll1) = {l1,l2,l3,l4} ;
            llpresspan[ip-1] = ll1;

            // Recombine Surface {ps1} ;
            // Plane Surface(ps1) = {ll1,lldisc[]} ;
            Plane Surface(ps1) = {ll1} ;
			Transfinite Surface(ps1) ;
            Recombine Surface {ps1} ;
            
            phys1 = ppoffset+phys0+i ;
            
            Physical Surface(Sprintf("PressPan_Cyl_%03g",ip),phys1) = {ps1};	// aire
            // phyl1 = ppoffset+phyl0+i ;
            // Physical Line(Sprintf("PressPan_Cyl_BND_%03g",ip),phyl1) = {l1,l2,l3,l4};	// frontera exterior
        EndFor
        
If (Npp == 0)
	llpresspan[] =  {};
EndIf

