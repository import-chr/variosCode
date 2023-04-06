<?php

namespace App\Http;

class Response {
    protected $view;

    public function __construct($view) {
        $this->view = $view;
    }
    
    /**
     * getView
     *
     * @return vista
     */
    public function getView() {
        return $this->view;
    }
    
    /**
     * send
     *
     * @return void
     * 
     * contenido para la vista
     */
    public function send() {
        $view = $this->getView();
        $content = file_get_contents(__DIR__ . "/../../views/{$view}.php");

        require __DIR__ . "/../../views/layout.php";
    }
}