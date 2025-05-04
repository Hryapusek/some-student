#pragma once

#include <string>
#include <iostream>

/*
  #include <program_level.h>
  #include <program_level.h>
  #include <program_level.h>

  tttt -> main.cc -> main.o - единица трансляции
  tttt -> parser.cc -> parser.o - единица трансляции
*/
namespace cjl
{
  class ProgramLevel
  {
   public:
    ProgramLevel() = default;  // {}

    ProgramLevel(std::string program, uint8_t level)
    {
      this->m_program = std::move(program);
      this->m_level = level;
    }

    friend std::ostream& operator<<(std::ostream& out, const ProgramLevel& level)
    {
      out << "m_level: " << static_cast<uint>(level.m_level) << "\t" << "m_program: " << level.m_program;
      return out;
    }

   private:
    std::string m_program;
    std::uint8_t m_level;
  };
}  // namespace cjl
