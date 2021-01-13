Info << "Reading field p\n" << endl;
volScalarField p(
  IOobject(
    "p",
    runTime.timeName(),
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
  ),
  mesh
);

Info << "Reading physical velocity field U\n" << endl;
volVectorField U(
  IOobject(
    "U",
    runTime.timeName(),
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
  ),
  mesh
);

Info << "Reading density field rho\n" << endl;
volScalarField rho(
  IOobject(
    "rho",
    runTime.timeName(),
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
  ),
  mesh
);

Info << "Reading momentum exchange field Ksl\n" << endl;
volScalarField Ksl(
  IOobject(
    "Ksl",
    runTime.timeName(),
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
  ),
  mesh
  // dimensionedScalar("0", dimensionSet(1, -3, -1, 0, 0), 1.0)
);

Info << "Reading voidFraction field voidFraction = (Vgas / Vparticle)\n" << endl;
volScalarField voidFraction(
  IOobject(
    "voidFraction",
    runTime.timeName(),
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
  ),
  mesh
);

Info << "Reading particle velocity field Us\n" << endl;
volVectorField Us(
  IOobject(
    "Us",
    runTime.timeName(),
    mesh,
    IOobject::MUST_READ,
    IOobject::AUTO_WRITE
  ),
  mesh
);

Info << "Reading/calculating face flux field phi\n" << endl;
surfaceScalarField phi(
  IOobject(
    "phi",
    runTime.timeName(),
    mesh,
    IOobject::READ_IF_PRESENT,
    IOobject::AUTO_WRITE
  ),
  linearInterpolate(U * voidFraction) & mesh.Sf()
);


Info << "Generating interstitial face flux field phiByVoidFraction\n" << endl;
surfaceScalarField phiByVoidFraction(
  IOobject(
    "phiByVoidFraction",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::NO_WRITE
  ),
  linearInterpolate(U) & mesh.Sf()
);

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);

singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence(
  incompressible::turbulenceModel::New(U, phi, laminarTransport)
);
