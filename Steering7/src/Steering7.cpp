// -*- C++ -*-
/*!
 * @file  Steering7.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "Steering7.h"
#include "SteeringDll.h"
using namespace std;

// Module specification
// <rtc-template block="module_spec">
static const char* steering7_spec[] =
  {
    "implementation_id", "Steering7",
    "type_name",         "Steering7",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "hmlab",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.confval", "0",
    // Widget
    "conf.__widget__.confval", "text",
    // Constraints
    ""
  };
// </rtc-template>

	int i=0;
	long c,d,e;
	double a=10000;
	LPDIRECTINPUT8		 m_pDI =NULL;
	LPDIRECTINPUTDEVICE8 m_pDID = NULL;
	LPDIRECTINPUTEFFECT  m_pDIE = NULL;
	HINSTANCE hInst;
	DIDEVCAPS m_DC;	
	WCHAR szAppName[] = L"Joystick";

	BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE* pdidInstance, VOID* pContext);
	BOOL CALLBACK EnumAxesCallback(LPCDIDEVICEOBJECTINSTANCE lpddoi, LPVOID pvRef);

	HWND hwnd =CreateWindow(TEXT("STATIC") , TEXT("joystick") ,
							WS_OVERLAPPEDWINDOW ,
							100 , 100 , 200 , 200 , NULL , NULL ,
							hInst , NULL);



/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Steering7::Steering7(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_forceIn("force", m_force),
    m_velocityOut("velocity", m_velocity),
    m_SteeringOut("Steering", m_Steering),
    m_AccelOut("Accel", m_Accel),
    m_BreakOut("Break", m_Break)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Steering7::~Steering7()
{
}



RTC::ReturnCode_t Steering7::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("force", m_forceIn);
  
  // Set OutPort buffer
  addOutPort("velocity", m_velocityOut);
  addOutPort("Steering", m_SteeringOut);
  addOutPort("Accel", m_AccelOut);
  addOutPort("Break", m_BreakOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("confval", m_confval, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Steering7::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Steering7::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Steering7::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Steering7::onActivated(RTC::UniqueId ec_id)
{
	m_force.data=0;
	m_velocity.data.va=0.0;
	m_velocity.data.vx=0.0;
	c=0;
	d=0;
	e=0;

	Steer::Steering::Act();

  return RTC::RTC_OK;
}


RTC::ReturnCode_t Steering7::onDeactivated(RTC::UniqueId ec_id)
{
	Steer::Steering::Dea();

  return RTC::RTC_OK;
}


RTC::ReturnCode_t Steering7::onExecute(RTC::UniqueId ec_id)
{
	if( m_forceIn.isNew() ){
		m_forceIn.read();
	}

	Steer::Steering::Exe(m_force.data);

	c= Steer::Steering::Xv(c);
	d= Steer::Steering::Yv(d);
	e= Steer::Steering::Zv(e);

	m_Steering.data= c;
	m_Accel.data =d;
	m_Break.data =e;
	m_velocity.data.vx = -0.005+m_velocity.data.vx+(d*0.5-2*e)/10000.0;
	m_velocity.data.va = double(c/200.0);

	if(m_velocity.data.vx >10.0){
		m_velocity.data.vx= 10.0;
	}

	else if(m_velocity.data.vx < 0.0){
		m_velocity.data.vx= 0.0;
	}

	cout << "vx=" << m_velocity.data.vx << endl;
	cout << "va=" << m_velocity.data.va << endl;

	/*
	m_SteeringOut.write();
	m_AccelOut.write();
	m_BreakOut.write();
	m_velocityOut.write();

	*/
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Steering7::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Steering7::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Steering7::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Steering7::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Steering7::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void Steering7Init(RTC::Manager* manager)
  {
    coil::Properties profile(steering7_spec);
    manager->registerFactory(profile,
                             RTC::Create<Steering7>,
                             RTC::Delete<Steering7>);
  }
  
};


