

class Tab {

    url: string;
    title: string;
    md5hash: string;
    name: string;
    mainTab: boolean = false;

    constructor(url: string, title: string, md5hash: string) {
        this.url = url;
        this.title = title;
        this.md5hash = md5hash;
        this.name = title;
        this.mainTab = false;
    }

    set active(active: boolean) {
        this.mainTab = active;
    }

    get active(): boolean {
        return this.mainTab;
    }
}

export default Tab;