

    Info << "***************************************************" << nl;
    Info << "Reading fracDissolFoam dictionary" << nl;
    IOdictionary fracDissolFoam
    (
        IOobject
        (
            "fracDissolFoamDict",
            runTime.system(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );
                                                       
    int nC;
    if( !fracDissolFoam.readIfPresent<int>("nC", nC) ){
    SeriousErrorIn("main")
    << "There is no nC parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }
    int nR;
    if( !fracDissolFoam.readIfPresent<int>("nR", nR) ){
    SeriousErrorIn("main")
    << "There is no nR parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }
	
	double nSurface;
    if( !fracDissolFoam.readIfPresent<double>("nSurface", nSurface) ){
    SeriousErrorIn("main")
    << "There is no nSurface parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }

    bool QCON;
    if( !fracDissolFoam.readIfPresent<bool>("QCON", QCON) ){
    SeriousErrorIn("main")
    << "There is no QCON parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }
    bool DEBUG;
    if( !fracDissolFoam.readIfPresent<bool>("DEBUG", DEBUG) ){
    SeriousErrorIn("main")
    << "There is no DEBUG parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }

    double Qmax;
    if( !fracDissolFoam.readIfPresent<double>("Qmax", Qmax) ){
    SeriousErrorIn("main")
    << "There is no Qmax parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }
	
    double Sh;
    if( !fracDissolFoam.readIfPresent<double>("Sh", Sh) ){
    SeriousErrorIn("main")
    << "There is no Sh parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }

    Info << "FractureFoamDict:            "             << nl;
    Info << "# of concentrations :        " << nC       << nl;
    Info << "# of reactions :             " << nR       << nl;
	Info << "Numbers of reactive surfaces:" << nSurface << nl;
    Info << "Constant Flow Rate:          " << QCON     << nl;
    Info << "Debugging:                   " << DEBUG    << nl;
    Info << "Max Flow Rate (QCON false):  " << Qmax     << nl;
    Info << "Sherwood number:  			  " << Sh       << nl;

    Info << "Reading fvSolution controls dictionary\n" << endl;
    const dictionary& controls = mesh.solutionDict().subDict("concentration");

    int nCycle;
    if( !controls.readIfPresent<int>("nCycle", nCycle) ){
    SeriousErrorIn("main")
    << "There is no nCycle parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }
    double tolerance;
    if( !controls.readIfPresent<double>("tolerance", tolerance) ){
    SeriousErrorIn("main")
    << "There is no tolerance parameter in fracDissolFoam dictionary"
    << exit(FatalError);
    }

    Info << "fvSolution.concentrationDict:"              << nl;
    Info << "# cycles:                    " << nCycle    << nl;
    Info << "tolerance:                   " << tolerance << nl << nl;

    Info << "Reading transportProperties\n" << nl;
    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );

    dimensionedScalar D0 (transportProperties.lookup("D0"));
    dimensionedScalar k0 (transportProperties.lookup("k0"));

    Info << "Constant difffusion coefficient in fractures" << endl;
    Info << "D0 = U0*L/Pe: " << D0 << endl;
    Info << "k0 = Da*U0/L: " << k0 << endl;

    Info << "***************************************************" << nl
         << endl;

