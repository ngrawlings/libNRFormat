//
//  JsonArray.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef JsonArray_hpp
#define JsonArray_hpp

#include <stdio.h>
#include "JsonValue.h"
#include <libnrcore/memory/Array.h>

namespace nrcore {
    
    class JsonArray : public JsonValue {
    public:
        JsonArray(String json);
        JsonArray(const JsonArray &json);
        virtual ~JsonArray();
        
        TYPE getType();
        String toString();
        
        bool parse(String json);
        
        Array< Ref<JsonValue> > getArray();
        
    protected:
        Array< Ref<JsonValue> > values;
    };
    
}

#endif /* JsonArray_hpp */
