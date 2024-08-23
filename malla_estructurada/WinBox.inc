// WinBox cylinders
// wboffset= 20000000;
 // Nwb  = 0;
WBCyl_R  =  {  } ;
WBCyl_d  =  {  } ;
WBCyl_H  =  {  } ;
WBCyl_z  =  {  } ;
/*
 Python specifies: 
 WBCyl_R={};
 WBCyl_d={};
 WBCyl_H={};
 WBCyl_z={};
 */


i = 0 ;
    For iwb In {1:Nwb}
        i = i + 1 ;
        p1 = wboffset+p0+4*i-3 ;	p2 = wboffset+p0+4*i-2 ;
        p3 = wboffset+p0+4*i-1 ;	p4 = wboffset+p0+4*i ;
        
        R  = WBCyl_R[iwb-1];
        dr = WBCyl_d[iwb-1];
        z1 = -0.5*Core_Z+WBCyl_z[iwb-1];
        z2 = -0.5*Core_Z+WBCyl_z[iwb-1] + WBCyl_H[iwb-1];
        Point(p1) = {R		, z1 , 0, 25*lcc} ;     
        Point(p2) = {R+dr	, z1 , 0, 25*lcc} ;     
        Point(p3) = {R+dr	, z2 , 0, 25*lcc} ;     
        Point(p4) = {R		, z2 , 0, 25*lcc} ;     
        l1 = wboffset+l0+4*i-3 ;	l2 = wboffset+l0+4*i-2 ;
        l3 = wboffset+l0+4*i-1 ;	l4 = wboffset+l0+4*i ;
        Line(l1) = {p1,p2} ;
        Line(l2) = {p2,p3} ;
        Line(l3) = {p3,p4} ;
        Line(l4) = {p4,p1} ;
        ll1 = wboffset+ll0+2*i-1 ;
        ps1 = wboffset+ll0+2*i ;
        Line Loop(ll1) = {l1,l2,l3,l4} ;
        llwinbox[iwb-1] = ll1;

        // Recombine Surface {ps1} ;
        // Plane Surface(ps1) = {ll1,lldisc[]} ;
        Plane Surface(ps1) = {ll1} ;
        phys1 = wboffset+phys0+i ;
        
        Physical Surface(Sprintf("WinBox_Cyl_%03g",iwb),phys1) = {ps1};	// 
        phyl1 = wboffset+phyl0+i ;
        Physical Line(Sprintf("WinBox_Cyl_BND_%03g",iwb),phyl1) = {l1,l2,l3,l4};	// frontera exterior
    EndFor


If (Nwb  == 0)
	llwinbox[] =  {};
EndIf




