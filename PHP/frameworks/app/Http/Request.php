<?php

namespace App\Http;

class Request {
    protected $segments = [];
    protected $controller;
    protected $method;

    public function __construct() {
        $this->segments = explode("/", $_SERVER['REQUEST_URI']);
        $this->setController();
        $this->setMethod();
    }
    
    /**
     * setController
     *
     * @return void
     * 
     * controlador del URL
     */
    public function setController() {
       $this->controller = empty($this->segments[1]) ? 'home' : $this->segments[1];
    }
    
    /**
     * setMethod
     *
     * @return void
     * 
     * configuracion de metodos
     */
    public function setMethod() {
        $this->method = empty($this->segments[2]) ? 'index' : $this->segments[2];
    }
    
    /**
     * getController
     *
     * @return name controller
     */
    public function getController() {
        $controller = ucfirst($this->controller);

        return "App\Http\Controllers\{$controller}Controller";
    }
        
    /**
     * getMethod
     *
     * @return method
     */
    public function getMethod() {
        return $this->method;
    }
    
    /**
     * send
     *
     * @return void
     * 
     * envia peticion
     */
    public function send() {
        $controller = $this->getController();
        $method = $this->getMethod();
        $response = call_user_func([new $controller, $method]);
        $response->send();
    }
}