//
//  JsonValue.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef JsonValue_hpp
#define JsonValue_hpp

#include <stdio.h>
#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class JsonValue {
    public:
        typedef enum {
            OBJECT,
            ARRAY,
            STRING,
            VALUE,
            INVALID
        } TYPE;
        
    public:
        JsonValue();
        virtual ~JsonValue();
        
        virtual TYPE getType();
        virtual String toString();
        
        static TYPE getJsonType(String json);
        static Ref<JsonValue> getJsonValue(String json);
    };
    
}

#endif /* JsonValue_hpp */
