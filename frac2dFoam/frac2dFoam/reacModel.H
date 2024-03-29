//  Linear reaction kinetics + transport corrected //


    double stoiTable[1][2] = {{1.0,-1.0}};   // Stoichiometric coeffs

    //double Sh = 8.0;
    double G  = 2*k0.value()/(D0.value()*Sh);

    RList[0]()  == nSurface*k0*CList[0]()/(1+G*H);
    dRList[0]() == nSurface*k0/(1+G*H);

