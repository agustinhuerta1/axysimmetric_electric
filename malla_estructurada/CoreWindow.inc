// CoreWindow, bounding box
// Bounding Box (or core window)
i = 1 ;
p1 = bboffset+p0+4*i-3 ;
p2 = bboffset+p0+4*i-2 ;
p3 = bboffset+p0+4*i-1 ;
p4 = bboffset+p0+4*i ;
rm = Rw ;
zm = 0 ;
Point(p1) = {Core_R_int, -0.5*Core_Z, 0, lcbb} ;
Point(p2) = {Core_R_out, -0.5*Core_Z, 0, lcbb} ;
Point(p3) = {Core_R_out, +0.5*Core_Z, 0, lcbb} ;
Point(p4) = {Core_R_int, +0.5*Core_Z, 0, lcbb} ;
l1 = bboffset+l0+4*i-3 ;
l2 = bboffset+l0+4*i-2 ;
l3 = bboffset+l0+4*i-1 ;
l4 = bboffset+l0+4*i ;
Line(l1) = {p1,p2} ;
Line(l2) = {p2,p3} ;
Line(l3) = {p3,p4} ;
Line(l4) = {p4,p1} ;


Transfinite Curve {l1} = nrc_Core_Window;
Transfinite Curve {l2} = nzc_Core_Window;
Transfinite Curve {l3} = nrc_Core_Window;
Transfinite Curve {l4} = nzc_Core_Window;


ll1 = bboffset+ll0+2*i-1 ;
ps1 = bboffset+ll0+2*i ;
Line Loop(ll1) = {l1,l2,l3,l4} ;
//Recombine Surface {ps1} ;
// Plane Surface(ps1) = {ll1,lldisc[], llpresspan[], llwinbox[], lldisc_presspan[] } ;
// Plane Surface(ps1) = {ll1,lldisc[], llpresspan[], llwinbox[], lldisc_presspan[], llesr_ins[] } ;
Plane Surface(ps1) = {ll1,lldisc[], llpresspan[], llwinbox[], lldisc_presspan[], llesr_ins[], ll_end_ring[] } ;
phys1 = bboffset+phys0+i ;
Physical Surface("Air",phys1) = {ps1};	// aire
phyl1 = bboffset+phyl0+i ;
Physical Line("Outer boundary",phyl1) = {l1,l2,l3,l4};	// frontera exterior
Physical Line("Outer boundary W/O PVM_NULL",phyl1+1) = {l1,l3,l4};	// frontera exterior sin borde PVM = 0
Physical Line("PVM_NULL",phyl1+2) = {l2};	// A = 0
