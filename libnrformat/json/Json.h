//
//  Json.hpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#ifndef Json_hpp
#define Json_hpp

#include <stdio.h>
#include "types/JsonValue.h"
#include "types/JsonArray.h"
#include "types/JsonObject.h"
#include "types/JsonString.h"
#include "types/JsonNumber.h"
#include "types/JsonInvalid.h"

#include <libnrcore/memory/String.h>

namespace nrcore {
    
    class Json {
    public:
        Json(String json);
        Json(JsonValue::TYPE type);
        Json(const Json &json);
        virtual ~Json();
        
        JsonValue::TYPE getType();
        Ref<JsonValue> getValue();
        
        String getStringValue(String path);
        int getIntValue(String path);
        Array< Ref<JsonValue> > getArray(String path);
        
        bool setValue(String path, Ref<JsonValue> value);
        
    protected:
        Ref<JsonValue> value;
    };
    
}

#endif /* Json_hpp */
