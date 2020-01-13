//
//  Csv.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 09/01/2020.
//  Copyright © 2020 Liquidsoft Studio. All rights reserved.
//

#ifndef Csv_hpp
#define Csv_hpp

#include <stdio.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/Memory.h>
#include <libnrcore/memory/String.h>
#include <libnrcore/memory/StringList.h>

namespace nrcore {

    class Csv {
    public:
        Csv();
        virtual ~Csv();
        
        bool loadData(String data);
        bool loadFile(String path);
        
        bool eof();
        StringList getEntry();
        
    protected:
        String data;
        int cursor;
    };

}

#endif /* Csv_hpp */
