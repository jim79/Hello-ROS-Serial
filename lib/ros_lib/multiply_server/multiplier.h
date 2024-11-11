#ifndef _ROS_SERVICE_multiplier_h
#define _ROS_SERVICE_multiplier_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multiply_server
{

static const char MULTIPLIER[] = "multiply_server/multiplier";

  class multiplierRequest : public ros::Msg
  {
    public:
      typedef int16_t _a_type;
      _a_type a;
      typedef int16_t _b_type;
      _b_type b;

    multiplierRequest():
      a(0),
      b(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_a;
      u_a.real = this->a;
      *(outbuffer + offset + 0) = (u_a.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_a.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->a);
      union {
        int16_t real;
        uint16_t base;
      } u_b;
      u_b.real = this->b;
      *(outbuffer + offset + 0) = (u_b.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->b);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_a;
      u_a.base = 0;
      u_a.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_a.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->a = u_a.real;
      offset += sizeof(this->a);
      union {
        int16_t real;
        uint16_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->b = u_b.real;
      offset += sizeof(this->b);
     return offset;
    }

    virtual const char * getType() override { return MULTIPLIER; };
    virtual const char * getMD5() override { return "e01e889cb1a7965611513515df5899bf"; };

  };

  class multiplierResponse : public ros::Msg
  {
    public:
      typedef int16_t _result_type;
      _result_type result;

    multiplierResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return MULTIPLIER; };
    virtual const char * getMD5() override { return "e2c2de4947863e4feccd94cb02ed28ea"; };

  };

  class multiplier {
    public:
    typedef multiplierRequest Request;
    typedef multiplierResponse Response;
  };

}
#endif
