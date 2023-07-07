

class Communication {

    tabs: string[] = [];

    constructor() {
        this.tabs = JSON.parse("[]");
    }

    get getTabs(): string {
        console.log("getTabs");
        return `[{"url":"https://www.google.com","md5":"8ffdefbdec956b595d257f0aaeefd623"}]`;
    }
}

export default Communication;