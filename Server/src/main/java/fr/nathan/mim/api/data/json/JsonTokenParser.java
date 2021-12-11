package fr.nathan.mim.api.data.json;

public class JsonTokenParser {

    private JsonToken type = JsonToken.UNKNOWN;
    private String value;
    private int position;

    public JsonToken getType() {
        return type;
    }
    public String getValue() {
        return value;
    }
    public int getPosition() {
        return position;
    }
    static JsonTokenParser getNextToken(String input){
        JsonTokenParser token = new JsonTokenParser();
        int maxLength = input.length();
        int i;

        for (i = 0; i < maxLength; i++) {
            char c = input.charAt(i);
            if (c == '{') {
                token.type = JsonToken.CURLY_OPEN;
                break;
            } else if (c == '}') {
                token.type = JsonToken.CURLY_CLOSE;
                break;
            } else if (c == '[') {
                token.type = JsonToken.ARRAY_OPEN;
                break;
            } else if (c == ']') {
                token.type = JsonToken.ARRAY_CLOSE;
                break;
            } else if (c == '"') {
                token.type = JsonToken.STRING;
                token.value = "";
                i++;
                do {
                    if (i != maxLength - 1) {
                        c = input.charAt(i++);
                        if (c != '"')
                            token.value += c;
                    }
                } while (c != '"');
                break;
            }
        }
        token.position = i;
        return token;
    }

    static int getNextTokenPosition( String str, char test) {

        long maxLength = str.length();
        int i;
        for (i = 0; i < maxLength; i++) {
            if (str.charAt(i) == test) break;
        }
        return i;
    }


}
