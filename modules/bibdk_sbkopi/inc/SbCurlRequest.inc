<?php

class SbCurlRequest extends MicroCURL {

  private $url, $parameters, $request;

  public function __construct ($request, $parameters, $xmlns, $url = null) {
    $this->url = $url;
    parent::microcurl();
    $this->setRequest($request, $xmlns);
    $this->setParameters($parameters);
    $this->set_post_xml($this->getPostXml());
  }

  public function call() {
    return $this->get($this->url);
  }

  public function getPostXml() {
    return $this->request->asXML();
  }

  private function setParameters($parameters) {
    foreach($parameters as $key => $value) {
      $this->request->addChild($key, $value);
    }
  }

  private function setRequest($request, $xmlns) {
    $this->request = new SimpleXMLElement("<$request/>");
    $this->request->addAttribute("xmlns", $xmlns);
  }

  public function getReponse() {
    return $this->get_status('http_code');
  }
}


class SbCurlRequestException extends Exception {

  private $params;

  public function setParams(array $params) {
    $this->params = $params;
  }

  public function getParams() {
    return $this->params;
  }
}
