//
//  main.cpp
//  UnitTests
//
//  Created by Nyhl Rawlings on 17/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include <iostream>
#include "../libnrformat/json/Json.h"
#include <libnrcore/memory/String.h>

#include <libnrdebug/UnitTests.h>

using namespace nrcore;

int main(int argc, const char * argv[]) {
    // insert code here...
    String _json("{\"params\":{\"processed\":\"0\",\"window_id\":\"1\"},\"command\":\"Task\",\"hash\":\"B1\", \"results\": {\"processed\":\"100\"}, \"number\":555}");
    
    Json json(_json);
    Ref<JsonValue> root = json.getValue();
    Ref<JsonValue> params = (dynamic_cast<JsonObject*>(root.getPtr()))->getValue("params");
    Ref<JsonValue> proccessed = (dynamic_cast<JsonObject*>(params.getPtr()))->getValue("processed");
    
    printf("%s\n", (dynamic_cast<JsonString*>(proccessed.getPtr()))->getValue().operator char *());
    
    String test = (dynamic_cast<JsonObject*>(root.getPtr()))->toString();
    printf("%s\n", test.operator char *());
    
    String v = json.getStringValue("params.processed");
    printf("%s\n", v.operator char *());
    
    v = json.getStringValue("command");
    printf("%s\n", v.operator char *());
    
    int num = json.getIntValue("number");
    printf("%d\n", num);
    
    Json arr("[\"12234567890\", \"0987654321\", 500, 400, 300, 200, 100, [12345,567890,9876543]]");
    Array< Ref<JsonValue> > values = arr.getArray("");
    for (int i=0; i<values.length(); i++) {
        if (values.get(i).getPtr()->getType() == JsonValue::STRING) {
            String v = ((JsonString*)values.get(i).getPtr())->getValue();
            printf("%s\n", v.operator char *());
        } else {
            String v = values.get(i).getPtr()->toString();
            printf("%s\n", v.operator char *());
        }
    }
    
    return 0;
}
