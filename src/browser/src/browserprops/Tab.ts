

class Tab {

    url: string;
    title: string;
    md5hash: string;
    name: string;

    constructor(url: string, title: string, md5hash: string) {
        this.url = url;
        this.title = title;
        this.md5hash = md5hash;
        this.name = title;
    }

    set active(active: boolean) {
        document.getElementById(this.md5hash).classList.toggle("active", true);
        const othertabs = document.getElementsByTagName("iframe");
        for (let i = 0; i < othertabs.length; i++) {
            if (othertabs[i].id != this.md5hash) {
                othertabs[i].classList.toggle("active", false);
            }
        }
    }

    get active(): boolean {
        return document.getElementById(this.md5hash).classList.contains("active");
    }
}

export default Tab;