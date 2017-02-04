#include <iostream>

// shorten help message (must go before the #include)
//#define STRIP_FLAG_HELP 1

#include <gflags/gflags.h>

#define VERSION "v1.0"

#define USAGE "this program parses flags given on command line \
 then forwards the arguments to the application"

// define usable flags for this program
DEFINE_bool(myBoolean, true, "Define 'myBoolean' with type 'bool'");
DEFINE_int32(myInt32, -32, "Define 'myInt32' with type 'int32'");
DEFINE_int64(myInt64, -64, "Define 'myInt64' with type 'int64'");
DEFINE_uint64(myUint64, 64, "Define 'myUint64' with type 'uint64'");
DEFINE_double(myDouble, 3.1415926, "Define 'myDouble' with type 'double'");
DEFINE_string(myString, "blabla", "Define 'myString' with type 'string'");

// declare usable flags for this program (defined in another compilation unit)
DECLARE_bool(hisBoolean);
DECLARE_int32(hisInt32);

// provide a sanity check for a flag
static bool validate_myInt32(const char* flagname, int value)
{
  if (value > 0 && value < 32768)
  {
    return true;
  }
  {
    std::cout << value << " is an invalid value for " << flagname << std::endl;
    return false;
  }
}

DEFINE_validator(myInt32, &validate_myInt32);


int main(int argc, char* argv[])
{
  gflags::SetVersionString(VERSION);

  gflags::SetUsageMessage(USAGE);

  std::cout << "print raw command line :" << std::endl;

  for(int i=0; i<argc; ++i)
  {
    std::cout << '[' << i << "] " << argv[i] << std::endl;
  }

  // change the default value
  FLAGS_myBoolean = false;

  // change the default value
  FLAGS_myBoolean = false;

  // parse the flags and, according to last argument :
  // - if false, put them at the beginning in command line
  // - if true, remove them from command line
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  std::cout << std::endl << "print flags only :" << std::endl;

  std::cout << "myBoolean = " << FLAGS_myBoolean << std::endl;
  std::cout << "myInt32 = " << FLAGS_myInt32 << std::endl;
  std::cout << "myInt64 = " << FLAGS_myInt64 << std::endl;
  std::cout << "myUint64 = " << FLAGS_myUint64 << std::endl;
  std::cout << "myDouble = " << FLAGS_myDouble << std::endl;
  std::cout << "myString = " << FLAGS_myString << std::endl;

  std::cout << std::endl << "print arguments only :" << std::endl;

  for(int i=0; i<argc; ++i)
  {
    std::cout << '[' << i << "] " << argv[i] << std::endl;
  }

  return 0;
}

