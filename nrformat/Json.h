//
//  Json.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 17/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Json_hpp
#define Json_hpp

#include <stdio.h>

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/String.h>
#include <libnrcore/memory/Array.h>
#include <libnrcore/memory/HashMap.h>

namespace nrcore {

    class Json {
    public:
        typedef enum {
            OBJECT,
            ARRAY,
            STRING,
            VALUE
        } TYPE;
        
    public:
        Json(String json);
        Json(const Json &json);
        virtual ~Json();
        
        bool parse(String json);
        
        String getString(String name);
        
    protected:
        TYPE type;
        
        HashMap<String> values;
    };
    
}

#endif /* Json_hpp */
