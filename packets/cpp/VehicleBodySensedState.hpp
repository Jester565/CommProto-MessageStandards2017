/**
VehicleBodySensedState

Copyright (C) 2016-2017 Northrup Grumman Collaboration Project.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(At your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef NGCP_VEHICLE_BODY_SENSED_STATE_HPP
#define NGCP_VEHICLE_BODY_SENSED_STATE_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct VehicleBodySensedState : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    VehicleBodySensedState(uint16_t vehicle_id = 0,
      int16_t x_accel = 0,
      int16_t y_accel = 0,
      int16_t z_accel = 0,
      int16_t roll_rate = 0,
      int16_t pitch_rate = 0,
      int16_t yaw_rate = 0)
      : CHAIN_ABSPACKET(VehicleBodySensedState),
      vehicle_id(vehicle_id),
      x_accel(x_accel),
      y_accel(y_accel),
      z_accel(z_accel),
      roll_rate(roll_rate),
      pitch_rate(pitch_rate),
      yaw_rate(yaw_rate)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << vehicle_id;
      obj << x_accel;
      obj << y_accel;
      obj << z_accel;
      obj << roll_rate;
      obj << pitch_rate;
      obj << yaw_rate;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> yaw_rate;
      obj >> pitch_rate;
      obj >> roll_rate;
      obj >> z_accel;
      obj >> y_accel;
      obj >> x_accel;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the VehicleBodySensedState packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleBodySensedState();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    //g/1000
    int16_t x_accel;
    //g/1000
    int16_t y_accel;
    //g/1000
    int16_t z_accel;
    //millirad/second
    int16_t roll_rate;
    //millirad/second
    int16_t pitch_rate;
    //millirad/second
    int16_t yaw_rate;
  };
} // ngcp
#endif // NGCP_VEHICLE_BODY_SENSED_STATE_HPP

