import Communication from './Comms';
import TabManager from './browserprops/TabManager';
import React, { ReactNode } from 'react';

const comms = new Communication();
const tabManager = new TabManager(comms);

const Context = React.createContext([comms, tabManager]);


class ContextProvider extends React.Component<{ children: ReactNode }> {

    render() {
        return (
            <Context.Provider value={[comms, tabManager]}>
                {this.props.children}
            </Context.Provider>
        );
    }
}

export { ContextProvider, Context };