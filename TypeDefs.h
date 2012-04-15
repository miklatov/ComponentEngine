#ifndef TYPEDEFS_H_INCLUDED
#define TYPEDEFS_H_INCLUDED

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

typedef unsigned long ObjectId;
typedef boost::property_tree::ptree Blueprint;
typedef unsigned short ComponentFlag;
typedef std::vector<std::string> Parameters;

namespace cFlag
{
    enum{   Obj=0,
            Gfx=1,
            Coords=2,
            Audio=4,
            Move=8,
            Input=16,
            Brain=32,
            Stats=64,
            Collision=128,
            Health=256,
            MAX=512,
        };


}

#endif // TYPEDEFS_H_INCLUDED
