//  Darcy flow solver

{
    #include "darcy.H"

    phi == -fvc::interpolate(H*H*H)*fvc::snGrad(p)*mag(mesh.Sf());
    U   == -(H*H*H)*fvc::grad(p);

    if (DEBUG)
    {
        #include "continuityErrs.H"
    }

    #include "avgU.H"               // Average flow velocity (Ux)

    U   == U/Uscale;                // Normalize U
    phi == phi/Uscale;              // Normalize surface volume flux


 	const char*  filenamea3 = "uscale" ;
	FILE *fout = fopen(filenamea3,"a"); 
	fprintf(fout,"%e\n",Uscale.value());
	fclose(fout);
	
    Info << "Flow solver done: Uscale = " << Uscale.value() << nl
         << "ExecutionTime = " << runTime.elapsedCpuTime()   << " s"
    	 << "    ClockTime = " << runTime.elapsedClockTime() << " s"
    	 << endl;
}
