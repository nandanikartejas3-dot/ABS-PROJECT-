/* Model step function */
void Subsystem_step(void)
{
  if (rtmIsMajorTimeStep(Subsystem_M)) {
    rtsiSetSolverStopTime(&Subsystem_M->solverInfo,
                          ((Subsystem_M->Timing.clockTick0+1) *
                           Subsystem_M->Timing.stepSize0));
  }

  if (rtmIsMinorTimeStep(Subsystem_M)) {
    Subsystem_M->Timing.t[0] = rtsiGetT(&Subsystem_M->solverInfo);
  }

  Subsystem_B.FilterCoefficient = (0.191 * Subsystem_U.Error -
    Subsystem_X.Filter_CSTATE) * 100.0;

  Subsystem_B.IntegralGain = 0.0001 * Subsystem_U.Error;

  Subsystem_Y.y = (30.009 * Subsystem_U.Error +
    Subsystem_X.Integrator_CSTATE) +
    Subsystem_B.FilterCoefficient;

  if (rtmIsMajorTimeStep(Subsystem_M)) {
    rt_ertODEUpdateContinuousStates(&Subsystem_M->solverInfo);
    ++Subsystem_M->Timing.clockTick0;
    Subsystem_M->Timing.t[0] = rtsiGetSolverStopTime(&Subsystem_M->
      solverInfo);
  }
}

/* Derivatives for root system: '<Root>' */
void Subsystem_derivatives(void)
{
  XDot_Subsystem_T *_rtXdot;
  _rtXdot = ((XDot_Subsystem_T *) Subsystem_M->derivs);

  _rtXdot->Filter_CSTATE = Subsystem_B.FilterCoefficient;
  _rtXdot->Integrator_CSTATE = Subsystem_B.IntegralGain;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  rtsiSetSimTimeStepPtr(&Subsystem_M->solverInfo, &Subsystem_M->Timing.
    simTimeStep);
  rtsiSetTPtr(&Subsystem_M->solverInfo, &rtmGetTPtr(Subsystem_M));
  rtsiSetStepSizePtr(&Subsystem_M->solverInfo, &Subsystem_M->Timing.
    stepSize0);
  rtsiSetdXPtr(&Subsystem_M->solverInfo, &Subsystem_M->derivs);

  rtsiSetContStatesPtr(&Subsystem_M->solverInfo, (real_T **)&
    Subsystem_M->contStates);
  rtsiSetNumContStatesPtr(&Subsystem_M->solverInfo, &Subsystem_M->Sizes
    .numContStates);
  rtsiSetContStateDisabledPtr(&Subsystem_M->solverInfo, (boolean_T**)&
    Subsystem_M->contStateDisabled);
  rtsiSetErrorStatusPtr(&Subsystem_M->solverInfo, (&rtmGetErrorStatus(
    Subsystem_M))));
  rtsiSetRTModelPtr(&Subsystem_M->solverInfo, Subsystem_M);

  rtsiSetSimTimeStep(&Subsystem_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Subsystem_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Subsystem_M->solverInfo, false);
  Subsystem_M->intgData.y = Subsystem_M->odeY;
  Subsystem_M->intgData.f[0] = Subsystem_M->odeF[0];
  Subsystem_M->intgData.f[1] = Subsystem_M->odeF[1];
  Subsystem_M->intgData.f[2] = Subsystem_M->odeF[2];
  Subsystem_M->contStates = ((X_Subsystem_T *) &Subsystem_X);
  Subsystem_M->contStateDisabled = ((XDis_Subsystem_T *) &
    Subsystem_XDis);
  Subsystem_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Subsystem_M->solverInfo, (void *)&Subsystem_M->
    intgData);
  rtsiSetSolverName(&Subsystem_M->solverInfo, "ode3");
  rtmSetTPtr(Subsystem_M, &Subsystem_M->Timing.tArray[0]);
  Subsystem_M->Timing.stepSize0 = 1.0;

  Subsystem_X.Filter_CSTATE = 0.001;
  Subsystem_X.Integrator_CSTATE = 0.0;
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}
