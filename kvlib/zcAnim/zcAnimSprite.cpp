#include "zcAnimSprite.h"
#include "zcAnimNode.h"
//#include "CCDeprecated.h"


using namespace cocos2d;

#if CC_SPRITEBATCHNODE_RENDER_SUBPIXEL
#define RENDER_IN_SUBPIXEL
#else
#define RENDER_IN_SUBPIXEL(__A__) ( (int)(__A__))
#endif

zcAnimSprite::zcAnimSprite(void)
{
    memset(&m_iMatrix,0,sizeof(cocos2dMATRIX));
    memset(&m_iColorTrans,0,sizeof(cocos2dCOLORFORM));
    m_bChangedMatrix = false;
    m_bChangedColor = false;
    m_bAnimFlipX = false;
    m_bAnimFlipY = false;
    m_bHadMatrix = false;
    m_bHadColor = false;
    m_nCid = 0;
}


zcAnimSprite::~zcAnimSprite(void)
{
}

zcAnimSprite* zcAnimSprite::createWithTexture(const cocos2d::Texture2D* texture,const cocos2d::Rect& rect,const cocos2d::Size parentSz)
{
    zcAnimSprite* sprite = new zcAnimSprite();
    if(sprite->initWithTexture((Texture2D*)texture,rect))
    {
        sprite->autorelease();
        sprite->m_iParentContentSize = parentSz;
        return sprite;
    }
    delete sprite;
    return NULL;
}

zcAnimSprite* zcAnimSprite::createWithFrame(const char *frameName , const cocos2d::Size &parentSz)
{
    zcAnimSprite* sprite = new zcAnimSprite();
    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
    if(frame == NULL)
    {
        delete sprite;
        return NULL;
    }
    if(sprite->initWithSpriteFrame(frame))
    {
        sprite->autorelease();
        sprite->m_iParentContentSize = parentSz;
        
        //add by ysp
        sprite->m_frameName = frameName;
        //end
        return sprite;
    }
    delete sprite;
    return NULL;
}


void zcAnimSprite::setMatrix(const cocos2dMATRIX& matrix)
{
    m_iMatrix = matrix;
    
    //	m_iMatrix.positionX-=getTextureRect().size.width/2;
    //	m_iMatrix.positionY+=getTextureRect().size.height/2;
    
    float scale = Director::getInstance()->getContentScaleFactor();
//    scale = 2;
    m_iMatrix.positionX/=scale;
    m_iMatrix.positionY/=scale;
    m_iMatrix.positionY = m_iParentContentSize.height-m_iMatrix.positionY;
    if(m_bAnimFlipX)
    {
        m_iMatrix.positionX = m_iParentContentSize.width-m_iMatrix.positionX;
        m_iMatrix.scaleX = -m_iMatrix.scaleX;
        m_iMatrix.rotateSkew1 = -m_iMatrix.rotateSkew1;
    }
    if(m_bAnimFlipY)
    {
        m_iMatrix.positionY = m_iParentContentSize.height-m_iMatrix.positionY;
        m_iMatrix.scaleY = -m_iMatrix.scaleY;
        m_iMatrix.rotateSkew0 = -m_iMatrix.rotateSkew0;
    }
    setPosition(m_iMatrix.positionX,m_iMatrix.positionY);
    
    printf("%s pos is (%f, %f)  \n", m_frameName.c_str(), m_iMatrix.positionX, m_iMatrix.positionY);
    
#ifdef WIN32
    m_iMatrix.positionX = size.width/2.0;
    m_iMatrix.positionY = size.height/2.0;
#endif//win32
    m_bHadMatrix = m_bChangedMatrix = true;
    //	m_bIsTransformDirty = m_bIsInverseDirty = true;
}
#define zc_min(m,n) ((m)<(n) ? (m) : (n))
#define zc_max(m,n) ((m)>(n) ? (m) : (n))
#define fixed8 0x00000100L
#define fixed8Tofloat(x) ((float)(x)/fixed8)
void zcAnimSprite::setColorForm(const cocos2dCOLORFORM& colorform)
{
    //chenged by zhangchen 2013,3,28
    /*
     * becaus transform color has error
     * this is error code
     *
     m_iColorTrans = colorform;
     m_bHadColor = m_bChangedColor = true;
     */
    
    m_iColorTrans = colorform;
    m_bHadColor = m_bChangedColor = true;
    setDirty(true);
    //    updateAnimColor();
    //    m_bChangedColor = true;
    //    if(_batchNode)
    //    {
    //        if (m_uAtlasIndex != CCSpriteIndexNotInitialized)
    //        {
    //            m_pobTextureAtlas->updateQuad(&m_iQuad, m_uAtlasIndex);
    //        }
    //        else
    //        {
    //            // no need to set it recursively
    //            // update dirty_, don't update recursiveDirty_
    //            setDirty(true);
    //        }
    //    }
}

void zcAnimSprite::setFlipX(bool fx)
{
    if(m_bAnimFlipX != fx)
    {
        m_iMatrix.positionX = m_iParentContentSize.width-m_iMatrix.positionX;
        m_iMatrix.scaleX = -m_iMatrix.scaleX;
        m_iMatrix.rotateSkew1 = -m_iMatrix.rotateSkew1;
        m_bAnimFlipX = fx;
        setPosition(Vec2(m_iMatrix.positionX,m_iMatrix.positionY));
        m_bChangedMatrix = true;
    }
}
void zcAnimSprite::setFlipY(bool fy)
{
    if(m_bAnimFlipY != fy)
    {
        m_iMatrix.positionY = m_iParentContentSize.height-m_iMatrix.positionY;
        m_iMatrix.scaleY = -m_iMatrix.scaleY;
        m_iMatrix.rotateSkew0 = -m_iMatrix.rotateSkew0;
        m_bAnimFlipY = fy;
        setPosition(m_iMatrix.positionX,m_iMatrix.positionY);
        m_bChangedMatrix = true;
    }
}

void zcAnimSprite::asSameAs(zcAnimSprite* sprite)
{
    if(sprite->m_bHadMatrix)
    {
        m_iMatrix=sprite->m_iMatrix;
        m_bHadMatrix = m_bChangedMatrix = true;
        setPosition(m_iMatrix.positionX,m_iMatrix.positionY);
    }
    if(sprite->m_bHadColor)
    {
        //changed by zhangchen 2013,3,28
        /*
         * the old code
         *
         m_iColorTrans = sprite->m_iColorTrans;
         m_bHadColor = m_bChangedColor = true;
         */
        setColorForm(sprite->m_iColorTrans);
    }
    m_bAnimFlipX = sprite->m_bAnimFlipX;
    m_bAnimFlipY = sprite->m_bAnimFlipY;
}


int zcAnimSprite::setCid(int cid)
{
    m_nCid = cid;
    return m_nCid;
}

int zcAnimSprite::getCid()
{
    return m_nCid;
}


void zcAnimSprite::setColor(const Color3B& color)
{
    Node::setColor(color);
    updateColor();
    m_bChangedColor = true;
    setDirty(true);
}
void zcAnimSprite::setOpacity(GLubyte opacity)
{
    Node::setOpacity(opacity);
    updateColor();
    m_bChangedColor = true;
    setDirty(true);
}


void zcAnimSprite::updateAnimMatrix()
{
    if(m_bChangedMatrix)
    {
        m_iQuad = _quad;
        m_bChangedColor = m_bHadColor;
        /*
         m_iQuad.bl.vertices.x = m_iQuad.bl.vertices.x * m_iMatrix.scaleX + m_iQuad.bl.vertices.y*m_iMatrix.rotateSkew1;// + m_iMatrix.positionX;
         m_iQuad.bl.vertices.y = m_iQuad.bl.vertices.x * m_iMatrix.rotateSkew0 + m_iQuad.bl.vertices.y*m_iMatrix.scaleY;// + m_iMatrix.positionY;
         m_iQuad.br.vertices.x = m_iQuad.br.vertices.x * m_iMatrix.scaleX + m_iQuad.br.vertices.y*m_iMatrix.rotateSkew1;// + m_iMatrix.positionX;
         m_iQuad.br.vertices.y = m_iQuad.br.vertices.x * m_iMatrix.rotateSkew0 + m_iQuad.br.vertices.y*m_iMatrix.scaleY;// + m_iMatrix.positionY;
         m_iQuad.tl.vertices.x = m_iQuad.tl.vertices.x * m_iMatrix.scaleX + m_iQuad.tl.vertices.y*m_iMatrix.rotateSkew1;// + m_iMatrix.positionX;
         m_iQuad.tl.vertices.y = m_iQuad.tl.vertices.x * m_iMatrix.rotateSkew0 + m_iQuad.tl.vertices.y*m_iMatrix.scaleY;// + m_iMatrix.positionY;
         m_iQuad.tr.vertices.x = m_iQuad.tr.vertices.x * m_iMatrix.scaleX + m_iQuad.tr.vertices.y*m_iMatrix.rotateSkew1;// + m_iMatrix.positionX;
         m_iQuad.tr.vertices.y = m_iQuad.tr.vertices.x * m_iMatrix.rotateSkew0 + m_iQuad.tr.vertices.y*m_iMatrix.scaleY;// + m_iMatrix.positionY;
         */
        zcAnimNode *node = (zcAnimNode*)getParent();
        const cocos2dMATRIX* matrix = node->getMatrix();
        Size sz = node->getContentSize();
        float halfw = sz.width/2;
        float halfh = sz.height/2;
        
        float sx = m_iMatrix.scaleX;
        float sy = m_iMatrix.scaleY;
        float r0 = m_iMatrix.rotateSkew0;
        float r1 = m_iMatrix.rotateSkew1;
        float px = m_iMatrix.positionX;
        float py = m_iMatrix.positionY;
        
        /*
         sx = sx*matrix->scaleX + r1*matrix->rotateSkew0 + 0;
         r1 = sx*matrix->rotateSkew1 + r1*matrix->scaleY + 0;
         r0 = r0*matrix->scaleX + sy*matrix->rotateSkew0 + 0;
         sy = r0*matrix->rotateSkew1 + sy*matrix->scaleY + 0;
         */
        //        px = (px)*matrix->scaleX + (py)*matrix->rotateSkew0 + matrix->positionX;
        //        py = (px)*matrix->rotateSkew1 + (py)*matrix->scaleY + matrix->positionY;
        
        //        px = (px-matrix->positionX)*matrix->scaleX + (py-matrix->positionY)*matrix->rotateSkew0 + matrix->positionX;
        //        py = (px-matrix->positionX)*matrix->rotateSkew1 + (py-matrix->positionY)*matrix->scaleY + matrix->positionY;
        
        /*
         m_iQuad.bl.vertices.x = (m_iQuad.bl.vertices.x-px);
         m_iQuad.bl.vertices.y = (m_iQuad.bl.vertices.y-py);
         m_iQuad.br.vertices.x = (m_iQuad.br.vertices.x-px);;
         m_iQuad.br.vertices.y = (m_iQuad.br.vertices.y-py);
         m_iQuad.tl.vertices.x = (m_iQuad.tl.vertices.x-px);
         m_iQuad.tl.vertices.y = (m_iQuad.tl.vertices.y-py);
         m_iQuad.tr.vertices.x = (m_iQuad.tr.vertices.x-px);
         m_iQuad.tr.vertices.y = (m_iQuad.tr.vertices.y-py);
         */
        
        float tl_x = (m_iQuad.tl.vertices.x-px) * sx + (m_iQuad.tl.vertices.y-py)*r1 + px;
        float tl_y = (m_iQuad.tl.vertices.x-px) * r0 + (m_iQuad.tl.vertices.y-py)*sy + py;
        float bl_x = (m_iQuad.bl.vertices.x-px) * sx + (m_iQuad.bl.vertices.y-py)*r1 + px;
        float bl_y = (m_iQuad.bl.vertices.x-px) * r0 + (m_iQuad.bl.vertices.y-py)*sy + py;
        float br_x = (m_iQuad.br.vertices.x-px) * sx + (m_iQuad.br.vertices.y-py)*r1 + px;
        float br_y = (m_iQuad.br.vertices.x-px) * r0 + (m_iQuad.br.vertices.y-py)*sy + py;
        float tr_x = (m_iQuad.tr.vertices.x-px) * sx + (m_iQuad.tr.vertices.y-py)*r1 + px;
        float tr_y = (m_iQuad.tr.vertices.x-px) * r0 + (m_iQuad.tr.vertices.y-py)*sy + py;
        
        float tl_x1 = (tl_x-halfw)*matrix->scaleX + (tl_y-halfh)*matrix->rotateSkew1 + matrix->positionX + halfw;
        float tl_y1 = (tl_x-halfw)*matrix->rotateSkew0 + (tl_y-halfh)*matrix->scaleY + matrix->positionY + halfh;
        
        float bl_x1 = (bl_x-halfw)*matrix->scaleX + (bl_y-halfh)*matrix->rotateSkew1 + matrix->positionX + halfw;
        float bl_y1 = (bl_x-halfw)*matrix->rotateSkew0 + (bl_y-halfh)*matrix->scaleY + matrix->positionY + halfh;
        
        float br_x1 = (br_x-halfw)*matrix->scaleX + (br_y-halfh)*matrix->rotateSkew1 + matrix->positionX + halfw;
        float br_y1 = (br_x-halfw)*matrix->rotateSkew0 + (br_y-halfh)*matrix->scaleY + matrix->positionY + halfh;
        
        float tr_x1 = (tr_x-halfw)*matrix->scaleX + (tr_y-halfh)*matrix->rotateSkew1 + matrix->positionX + halfw;
        float tr_y1 = (tr_x-halfw)*matrix->rotateSkew0 + (tr_y-halfh)*matrix->scaleY + matrix->positionY + halfh;
        
        /*
         float tl_x = (m_iQuad.tl.vertices.x) * sx + (m_iQuad.tl.vertices.y)*r1 + px;
         float tl_y = (m_iQuad.tl.vertices.x) * r0 + (m_iQuad.tl.vertices.y)*sy + py;
         float bl_x = (m_iQuad.bl.vertices.x) * sx + (m_iQuad.bl.vertices.y)*r1 + px;
         float bl_y = (m_iQuad.bl.vertices.x) * r0 + (m_iQuad.bl.vertices.y)*sy + py;
         float br_x = (m_iQuad.br.vertices.x) * sx + (m_iQuad.br.vertices.y)*r1 + px;
         float br_y = (m_iQuad.br.vertices.x) * r0 + (m_iQuad.br.vertices.y)*sy + py;
         float tr_x = (m_iQuad.tr.vertices.x) * sx + (m_iQuad.tr.vertices.y)*r1 + px;
         float tr_y = (m_iQuad.tr.vertices.x) * r0 + (m_iQuad.tr.vertices.y)*sy + py;
         */
#if ZC_DEBUG==1
        CCLOG("tl(%f,%f)",tl_x,tl_y);
        CCLOG("bl(%f,%f)",bl_x,bl_y);
        CCLOG("br(%f,%f)",br_x,br_y);
        CCLOG("tr(%f,%f)",tr_x,tr_y);
#endif//ZC_DEBUG==1
        m_iQuad.bl.vertices.x = bl_x1;
        m_iQuad.bl.vertices.y = bl_y1;
        m_iQuad.br.vertices.x = br_x1;// + m_iMatrix.positionX;
        m_iQuad.br.vertices.y = br_y1;// + m_iMatrix.positionY;
        m_iQuad.tl.vertices.x = tl_x1;// + m_iMatrix.positionX;
        m_iQuad.tl.vertices.y = tl_y1;// + m_iMatrix.positionY;
        m_iQuad.tr.vertices.x = tr_x1;// + m_iMatrix.positionX;
        m_iQuad.tr.vertices.y = tr_y1;// + m_iMatrix.positionY;
        /*
         // what is the fuck, this is err , i think that the memory overbrim , more then 32 bit value;
         m_iQuad.bl.vertices.x = (m_iQuad.bl.vertices.x-px) * sx + (m_iQuad.bl.vertices.y-py)*r1 + px;
         m_iQuad.bl.vertices.y = (m_iQuad.bl.vertices.x-px) * r0 + (m_iQuad.bl.vertices.y-py)*sy + py;
         m_iQuad.br.vertices.x = (m_iQuad.br.vertices.x-px) * sx + (m_iQuad.br.vertices.y-py)*r1 + px;// + m_iMatrix.positionX;
         m_iQuad.br.vertices.y = (m_iQuad.br.vertices.x-px) * r0 + (m_iQuad.br.vertices.y-py)*sy + py;// + m_iMatrix.positionY;
         m_iQuad.tl.vertices.x = (m_iQuad.tl.vertices.x-px) * sx + (m_iQuad.tl.vertices.y-py)*r1 + px;// + m_iMatrix.positionX;
         m_iQuad.tl.vertices.y = (m_iQuad.tl.vertices.x-px) * r0 + (m_iQuad.tl.vertices.y-py)*sy + py;// + m_iMatrix.positionY;
         m_iQuad.tr.vertices.x = (m_iQuad.tr.vertices.x-px) * sx + (m_iQuad.tr.vertices.y-py)*r1 + px;// + m_iMatrix.positionX;
         m_iQuad.tr.vertices.y = (m_iQuad.tr.vertices.x-px) * r0 + (m_iQuad.tr.vertices.y-py)*sy + py;// + m_iMatrix.positionY;
         */
#if ZC_DEBUG==1
        CCLOG("matrix");
        CCLOG("%f,%f",sx,r0);
        CCLOG("%f,%f",r1,sy);
        CCLOG("%f,%f",px,py);
        CCLOG("tl(%f,%f),tl'(%f,%f)",_quad.tl.vertices.x,_quad.tl.vertices.y,m_iQuad.tl.vertices.x,m_iQuad.tl.vertices.y);
        CCLOG("bl(%f,%f),bl'(%f,%f)",_quad.bl.vertices.x,_quad.bl.vertices.y,m_iQuad.bl.vertices.x,m_iQuad.bl.vertices.y);
        CCLOG("br(%f,%f),br'(%f,%f)",_quad.br.vertices.x,_quad.br.vertices.y,m_iQuad.br.vertices.x,m_iQuad.br.vertices.y);
        CCLOG("tr(%f,%f),tr'(%f,%f)",_quad.tr.vertices.x,_quad.tr.vertices.y,m_iQuad.tr.vertices.x,m_iQuad.tr.vertices.y);
#endif//ZC_DEBUG==1
        m_bChangedMatrix = false;
    }
}

void zcAnimSprite::updateAnimColor()
{
    if(m_bChangedColor)
    {
        GLubyte r,g,b,a;
        a = _realOpacity;
        r = _realColor.r;
        g = _realColor.g;
        b = _realColor.b;
        if(m_iColorTrans.hasMultTerms)
        {
            r = (r * fixed8Tofloat(m_iColorTrans.redMultTerm));
            g = (g * fixed8Tofloat(m_iColorTrans.greenMultTerm));
            b = (b * fixed8Tofloat(m_iColorTrans.blueMultTerm));
            a = (a * fixed8Tofloat(m_iColorTrans.alphaMultTerm));
        }
        if(m_iColorTrans.hasAddTerms)
        {
            r = zc_max(0, zc_min(r+m_iColorTrans.redAddTerm, 255));
            g = zc_max(0, zc_min(g+m_iColorTrans.greenAddTerm, 255));
            b = zc_max(0, zc_min(b+m_iColorTrans.blueAddTerm, 255));
            a = zc_max(0, zc_min(a+m_iColorTrans.alphaAddTerm, 255));
        }
        
        m_iQuad.tl.colors = Color4B(r, g, b, a);
        m_iQuad.bl.colors = Color4B(r, g, b, a);
        m_iQuad.br.colors = Color4B(r, g, b, a);
        m_iQuad.tr.colors = Color4B(r, g, b, a);
        
        m_bChangedColor = false;
    }
}


void zcAnimSprite::updateColor(void)
{
    Sprite::updateColor();
    return;
    
    Color4B color4 = { _displayedColor.r, _displayedColor.g, _displayedColor.b, _displayedOpacity };
    
    // special opacity for premultiplied textures
    if (_opacityModifyRGB)
    {
        color4.r *= _displayedOpacity/255.0f;
        color4.g *= _displayedOpacity/255.0f;
        color4.b *= _displayedOpacity/255.0f;
    }
    
    _quad.bl.colors = color4;
    _quad.br.colors = color4;
    _quad.tl.colors = color4;
    _quad.tr.colors = color4;
    
    //    m_iQuad.bl.colors = color4;
    //    m_iQuad.br.colors = color4;
    //    m_iQuad.tl.colors = color4;
    //    m_iQuad.tr.colors = color4;
    
    // renders using batch node
    if (_batchNode)
    {
        if (_atlasIndex != INDEX_NOT_INITIALIZED)
        {
            m_bChangedMatrix = true;
            updateAnimMatrix();
            updateAnimColor();
            
            _textureAtlas->updateQuad(&m_iQuad, _atlasIndex);
            _recursiveDirty = false;
            setDirty(false);
        }
        else
        {
            // no need to set it recursively
            // update dirty_, don't update recursiveDirty_
            setDirty(true);
        }
    }
    
    // self render
    // do nothing
}

/** updates the quad according the the rotation, position, scale values. */
void zcAnimSprite::updateTransform(void)
{
    CCAssert(_batchNode, "updateTransform is only valid when CCSprite is being rendered using an CCSpriteBatchNode");
    
    // recalculate matrix only if it is dirty
    if( isDirty() ) {
        
        // If it is not visible, or one of its ancestors is not visible, then do nothing:
        if( !_visible || ( _parent && _parent != _batchNode && ((zcAnimSprite*)_parent)->_shouldBeHidden) )
        {
            _quad.br.vertices = _quad.tl.vertices = _quad.tr.vertices = _quad.bl.vertices = Vec3(0,0,0);
            _shouldBeHidden = true;
        }
        else
        {
            _shouldBeHidden = false;
            
            if( ! _parent || _parent == _batchNode )
            {
                _transformToBatch = getNodeToParentTransform();
            }
            else
            {
                CCAssert( dynamic_cast<Sprite*>(_parent), "Logic error in CCSprite. Parent must be a CCSprite");
                _transformToBatch =  getNodeToParentTransform() * ((zcAnimSprite*)_parent)->getNodeToParentTransform();
            }
            
            //
            // calculate the Quad based on the Affine Matrix
            //
            
            Size size = _rect.size;
            
            float x1 = _offsetPosition.x;
            float y1 = _offsetPosition.y;
            
            float x2 = x1 + size.width;
            float y2 = y1 + size.height;
            
            float x = _transformToBatch.m[3];
            float y = _transformToBatch.m[7];
            
            float cr = _transformToBatch.m[0];
            float sr = _transformToBatch.m[4];
            float cr2 = _transformToBatch.m[5];
            float sr2 = _transformToBatch.m[1];
            float ax = x1 * cr - y1 * sr2 + x;
            float ay = x1 * sr + y1 * cr2 + y;
            
            float bx = x2 * cr - y1 * sr2 + x;
            float by = x2 * sr + y1 * cr2 + y;
            
            float cx = x2 * cr - y2 * sr2 + x;
            float cy = x2 * sr + y2 * cr2 + y;
            
            float dx = x1 * cr - y2 * sr2 + x;
            float dy = x1 * sr + y2 * cr2 + y;
            
            _quad.bl.vertices = Vec3( RENDER_IN_SUBPIXEL(ax), RENDER_IN_SUBPIXEL(ay), getPositionZ() );
            _quad.br.vertices = Vec3( RENDER_IN_SUBPIXEL(bx), RENDER_IN_SUBPIXEL(by), getPositionZ() );
            _quad.tl.vertices = Vec3( RENDER_IN_SUBPIXEL(dx), RENDER_IN_SUBPIXEL(dy), getPositionZ() );
            _quad.tr.vertices = Vec3( RENDER_IN_SUBPIXEL(cx), RENDER_IN_SUBPIXEL(cy), getPositionZ() );
        }
        //translate cocos2d matrix with swf matrix
        updateAnimMatrix();
        updateAnimColor();
        //        m_pobTextureAtlas->updateQuad(&_quad, m_uAtlasIndex);
        _textureAtlas->updateQuad(&m_iQuad, _atlasIndex);
        _recursiveDirty = false;
        setDirty(false);
    }
    //
    // MARMALADE CHANGED
    // recursively iterate over children
    /*    if( m_bHasChildren )
     {
     // MARMALADE: CHANGED TO USE CCNode*
     // NOTE THAT WE HAVE ALSO DEFINED virtual CCNode::updateTransform()
     arrayMakeObjectsPerformSelector(m_pChildren, updateTransform, CCSprite*);
     }*/
    Node::updateTransform();
    
#if CC_SPRITE_DEBUG_DRAW==2
    // draw bounding box
    CCPoint vertices[4] = {
        ccp( _quad.bl.vertices.x, _quad.bl.vertices.y ),
        ccp( _quad.br.vertices.x, _quad.br.vertices.y ),
        ccp( _quad.tr.vertices.x, _quad.tr.vertices.y ),
        ccp( _quad.tl.vertices.x, _quad.tl.vertices.y ),
    };
    ccDrawPoly(vertices, 4, true);
#endif // CC_SPRITE_DEBUG_DRAW
    
}


void zcAnimSprite::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags)
{
    CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
    
    CCAssert(!_batchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");
    
    CC_NODE_DRAW_SETUP();
    
    GL::blendFunc( _blendFunc.src, _blendFunc.dst );
    
    if (_texture != NULL)
    {
        GL::bindTexture2D( _texture->getName() );
    }
    else
    {
        GL::bindTexture2D(0);
    }
    
    //
    // Attributes
    //
    
    GL::enableVertexAttribs( GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX );
    
    updateAnimMatrix();
    updateAnimColor();
#define kQuadSize sizeof(m_iQuad.bl)
    long offset = (long)&m_iQuad;
    
    // vertex
    int diff = offsetof( V3F_C4B_T2F, vertices);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));
    
    // texCoods
    diff = offsetof( V3F_C4B_T2F, texCoords);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));
    
    // color
    diff = offsetof( V3F_C4B_T2F, colors);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));
    
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    CHECK_GL_ERROR_DEBUG();
    
    
#if CC_SPRITE_DEBUG_DRAW == 1
    // draw bounding box
    CCPoint vertices[4]={
        ccp(_quad.tl.vertices.x,_quad.tl.vertices.y),
        ccp(_quad.bl.vertices.x,_quad.bl.vertices.y),
        ccp(_quad.br.vertices.x,_quad.br.vertices.y),
        ccp(_quad.tr.vertices.x,_quad.tr.vertices.y),
    };
    ccDrawPoly(vertices, 4, true);
#elif CC_SPRITE_DEBUG_DRAW == 2
    // draw texture box
    CCSize s = this->getTextureRect().size;
    CCPoint offsetPix = this->getOffsetPosition();
    CCPoint vertices[4] = {
        ccp(offsetPix.x,offsetPix.y), ccp(offsetPix.x+s.width,offsetPix.y),
        ccp(offsetPix.x+s.width,offsetPix.y+s.height), ccp(offsetPix.x,offsetPix.y+s.height)
    };
    ccDrawPoly(vertices, 4, true);
#endif // CC_SPRITE_DEBUG_DRAW
    
    CC_INCREMENT_GL_DRAWS(1);
    
    CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
}
