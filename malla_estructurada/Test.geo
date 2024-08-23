SetFactory("OpenCASCADE");


Mesh.MeshSizeExtendFromBoundary = 1;
Mesh.MeshSizeFromPoints = 1;
Mesh.MeshSizeFromCurvature = 1;
Mesh.Algorithm = 6;
Mesh.RecombineAll = 0;
Mesh.FlexibleTransfinite = 0;
Mesh.ElementOrder = 1;
Mesh.SubdivisionAlgorithm = 0; // Default 0
General.Axes = 0; // Default 0: None

Include "parameters.inc";
Hr = Nr*(lr+2*ei); 
Hz = Nz*(lz+2*ei)+(Nz-1)*es; 
Ro = Rw-0*Hr/2;
Zo = -0.5*Core_Z+0.015;

// MESH CONTROL

TOL = 1.5*1E-3;
nrc_cond = 2 + 1*Ceil(1*lr/TOL) + 26;
nzc_cond = 2 + 1*Ceil(1*lz/TOL) + 26*2 ;


nzc_intra_disk = 2 + 2*Ceil(2*(lz+2*ei)/TOL) ;
nrc_intra_disk = 2 + 2*Ceil(2*(Nr*(lr+2*ei)/TOL) );

nzc_inter_disk =  2 + Ceil(10*es/TOL);

nrc_Core_Window = 2 + 1*Ceil(1*(Core_R_out-Core_R_int) / (1*TOL )) ;
nzc_Core_Window = 2 + 1*Ceil(1*Core_Z / (1*TOL) ) ;
    

lci = ei/4 ;
lcc = lci ;
lcbb = 100*lci ;
Include "Winding_1_darwin.inc";
Include "Presspan.inc";
Include "WinBox.inc";
Include "Electrostatic_ring_v2.inc";
Include "End_ring.inc";
Include "CoreWindow.inc";
