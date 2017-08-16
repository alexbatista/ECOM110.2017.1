.h

#define SLOP_REG 0x0120
static void (*__write)(uint8_t);
static void (*__read)(uint8_t*);

typedef enum {
    Write,
    Read
} __attribute__((__packed__)) ICCommandType;


struct{
    union {
        uint16_t full;
        struct {
            uint8_t low;
            uint8_t high;
        } bytes;
    } address;
    ICCommandType type;
    uint8_t data;
} ICCommand;

void ICCommandSet(ICCommand *cmd, uint16_t address, ICCommandType type, uint8_t data) {
    cmd->address = address;
    cmd->type = type;
    cmd->data = data;
}

void ACCCommandExec(ICCommand *cmd) {
    //__open();
    __write(cmd->address.bytes.high);
    __write(cmd->address.bytes.low);
    __write(cmd->type);
    if(cmd->type == Write) {
        __write(cmd->data); //CONFIG
    } else {
        __read(&cmd->data);
    }
    //__close();
}

void ACCDriverInit(void (*write)(uint8_t), void (*read)(uint8_t*)) {
    __write = write;
    __read = read;
}

=======================

void SPIWrite(...) {}
data SPIRead(...) {}

int main() {
    ACCDriverInit(SPIRead, SPIWrite);
    ICCommand cmd;
    ICCommandSet(&cmd, SLOP_REG, Write, 0b00011001);
    ACCCommandExec(cmd);
    ICCommandSet(&cmd, TAP_REG, Read, 0);
    ACCCommandExec(cmd);
    printf("Result: %d\n", cmd->data);



    uint8_t buffer[4];
    ICCommandSet(&cmd, TAP_REG, Read, &buffer);


}
