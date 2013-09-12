/**
 * @file   mk2_gio_hardware_interface.hpp
 * @author Ugo Cupcic <ugo@shadowrobot.com>
 *
* Copyright 2013 Shadow Robot Company Ltd.
*
* This program is Proprietary software: you cannot redistribute it or modify it
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.
*
*
 * @brief The RoNeX mk2 general IO module data to be stored in the HardwareInterface.
 *
 *
 */

#ifndef _MK2_GIO_HARDWARE_INTERFACE_H_
#define _MK2_GIO_HARDWARE_INTERFACE_H_

#include <pr2_hardware_interface/hardware_interface.h>
#include <sr_ronex_external_protocol/Ronex_Protocol_0x02000001_GIO_00.h>
#include <vector>

namespace ronex
{
  class GeneralIOCommand
  {
  public:
    std::vector<bool> digital_;

    struct PWM
    {
      unsigned short int period;
      unsigned short int on_time_0;
      unsigned short int on_time_1;
    };

    std::vector<PWM> pwm_;
    unsigned short int pwm_clock_divider_;
  };

  class GeneralIOState
  {
  public:
    std::vector<bool> digital_;
    std::vector<unsigned short int> analogue_;
  };

  /**
   * This contains the command and state to be stored as a
   *  CustomHW in the pr2 hardware interface. Makes it possible
   *  to access the RoNeX data from the controllers as well as
   *  the driver.
   *
   * The command and state are a slightly higher level representation
   *  of the definitions used in the protocol header:
   *    sr_ronex_external_protocol/Ronex_Protocol_0x02000001_GIO_00.h
   */
  class GeneralIO
    : public pr2_hardware_interface::CustomHW
  {
  public:
    GeneralIOState state_;
    GeneralIOCommand command_;
  };
}
/* For the emacs weenies in the crowd.
Local Variables:
   c-basic-offset: 2
End:
*/

#endif /* _MK2_GIO_HARDWARE_INTERFACE_H_ */
